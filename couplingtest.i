[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 10
  xmax = 0.304 # Length of test chamber
  ymax = 0.0257 # Test chamber radius
[]

[Variables]
  [./pressure]
  [../]
  [./temperature]
  [../]
[]

[AuxVariables]
  [./velocity_x]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./velocity_y]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./velocity_z]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./darcy_pressure]
    type = Darcy
    variable = pressure
  [../]
  [./heat_conduction]
    type = HeatConduction
    variable = temperature
  [../]
  [./Heat_convection]
    type = HeatConvection
    variable = temperature
    cpressure = pressure
  [../]
[]

[Materials]
  [./Porous_medium]
    type = Porous
  [../]
[]

[BCs]
  [./inlet]
    type = DirichletBC
    variable = pressure
    boundary = left
    value = 4000 # (Pa).
  [../]
  [./outlet]
    type = DirichletBC
    variable = pressure
    boundary = right
    value = 0 # (Pa) (K).
  [../]
  [./inlet_temperature]
    type = DirichletBC
    variable = temperature
    boundary = left
    value = 350 # (C)
  [../]
  [./outlet_temperature]
    type = HeatConductionOutflow
    variable = temperature
    boundary = right
  [../]

[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = X
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[] 
