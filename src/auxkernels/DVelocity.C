#include "DVelocity.h"

template <>
InputParameters
validParams<DVelocity>()
{
  InputParameters params = validParams<AuxKernel>();

  MooseEnum component("x y z");

  params.addRequiredCoupledVar("cpressure", "The pressure field");
  return params;
}

DVelocity::DVelocity(const InputParameters & parameters) : AuxKernel(parameters),

  _component(getParam<MooseEnum>("component")),
  _pressure_gradient(coupledGradient("cpressure")),
  _permeability(getMaterialProperty<Real>("permeability")),
  _viscosity(getMaterialProperty<Real>("viscosity"))
{
}

Real
DVelocity::computeValue()
{
  return -(_permeability[_qp] / _viscosity[_qp]) * _pressure_gradient[_qp](_component);
}
