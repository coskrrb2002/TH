#include "HeatConvection.h"

template <>
InputParameters
validParams<HeatConvection>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("cpressure", "This is the pressure from darcy flow");

  return params;
}

HeatConvection::HeatConvection(const InputParameters & parameters) : Kernel(parameters),

// Coupling gradient variable
    _pressure_gradient(coupledGradient("cpressure")),

    _pressure_var(coupled("cpressure")),

    _permeability(getMaterialProperty<Real>("permeability")),
    _porosity(getMaterialProperty<Real>("porosity")),
    _viscosity(getMaterialProperty<Real>("viscosity")),
    _density(getMaterialProperty<Real>("density")),
    _heat_capacity(getMaterialProperty<Real>("heat_capacity"))

{
}

Real
HeatConvection::computeQpResidual()
{
RealVectorValue velocity = _porosity[_qp] * -(_permeability[_qp] / _viscosity[_qp]) * _pressure_gradient[_qp];

return _heat_capacity[_qp] * _test[_i][_qp] * (velocity * _grad_u[_qp]);
}


Real
HeatConvection::computeQpJacobian()
{
RealVectorValue velocity = _porosity[_qp] * -(_permeability[_qp] / _viscosity[_qp]) * _pressure_gradient[_qp];
return _heat_capacity[_qp] * _test[_i][_qp] * (velocity * _grad_phi[_j][_qp]);
}

Real
HeatConvection::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _pressure_var)
  {
    RealVectorValue velocity =
        _porosity[_qp] * -(_permeability[_qp] / _viscosity[_qp]) * _grad_phi[_j][_qp];
    return _heat_capacity[_qp] * _test[_i][_qp] * (_grad_u[_qp] * velocity);
  }

  return 0.0;
}
