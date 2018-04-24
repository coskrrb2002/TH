#ifndef POROUS_H
#define POROUS_H

#include "Material.h"

class Porous;

template <>
InputParameters validParams<Porous>();

class Porous : public Material
{
public:
  Porous(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;


  MaterialProperty<Real> & _permeability;
  MaterialProperty<Real> & _porosity;
  MaterialProperty<Real> & _viscosity;
  MaterialProperty<Real> & _thermal_conductivity; //Thermal conductivity(k)
  MaterialProperty<Real> & _density;
  MaterialProperty<Real> & _heat_capacity;



};

#endif
