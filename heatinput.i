[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 10
  xmax = 0.304 # Length of test chamber
  ymax = 0.0257 # Test chamber radius
[]

[Variables]
  [./temperature]
  [../]
[]

[Kernels]
  [./heat_transfer]
    type = HeatConduction
    variable = temperature
  [../]
[]

[BCs]
  [./inlet_T]
    type = DirichletBC
    variable = temperature
    boundary = left
    value = 350 # (Pa) (K).
  [../]
  [./outlet_T]
    type = DirichletBC
    variable = temperature
    boundary = right
    value = 100 # (K).
  [../]
[]
[Materials]
  [./porous_m]
    type = Porous
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
