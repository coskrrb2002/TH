#include "Porous.h"

template<>
InputParameters
validParams<Porous>()
{
  InputParameters params = validParams<Material>();
  params.addParam<Real>("permeability", 8.451E-10, "The Initial");
  params.addParam<Real>("porosity", 0.25952, "The Initial");
  params.addParam<Real>("viscosity", 0.000798, "The Initial");
  params.addParam<Real>("thermal_conductivity", 13.484352, "The Initial");
  params.addParam<Real>("density", 6182.23114, "The Initial");
  params.addParam<Real>("heatcapacity", 3840920.313, "The Initial");

  return params;
}

Porous::Porous(const InputParameters & parameters) : Material(parameters),
//Porous medium properties
  _permeability(declareProperty<Real>("permeability")),
  _porosity(declareProperty<Real>("porosity")),
  _viscosity(declareProperty<Real>("viscosity")),

//Thermal properties
    _thermal_conductivity(declareProperty<Real>("thermal_conductivity")),  //thermal conductivity (k)
    _density(declareProperty<Real>("density")),
    _heat_capacity(declareProperty<Real>("heat_capacity"))
{
}

void
Porous::computeQpProperties()
{
  _permeability[_qp] = 8.451E-10;
  _porosity[_qp] = 0.25952;
 _viscosity[_qp] = 0.000798;

_thermal_conductivity[_qp] = 13.484352;

_density[_qp] = 6182.23114;
 _heat_capacity[_qp] = 3840920.313;

}
