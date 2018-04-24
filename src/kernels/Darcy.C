#include "Darcy.h"

template<>
InputParameters validParams<Darcy>()
{
 InputParameters params = validParams<Kernel>();
 return params; 
}

Darcy::Darcy(const InputParameters & parameters) : Kernel(parameters),

    _permeability(getMaterialProperty<Real>("permeability")),
    _viscosity(getMaterialProperty<Real>("viscosity"))

{
}


Real
Darcy::computeQpResidual()
{
  return (_permeability[_qp] / _viscosity[_qp]) * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
Darcy::computeQpJacobian()
{
  return (_permeability[_qp] / _viscosity[_qp]) * _grad_test[_i][_qp] * _grad_phi[_j][_qp];
}
