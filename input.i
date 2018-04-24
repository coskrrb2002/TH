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
[]

[Kernels]
  [./darcy_pressure]
    type = Darcy
    variable = pressure
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
