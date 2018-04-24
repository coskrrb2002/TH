#ifndef DVELOCITY_H
#define DVELOCITY_H

#include "AuxKernel.h"

template <>
InputParameters validParams<DVelocity>();

class DVelocity : public AuxKernel
{
public: DVelocity(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;

  int _component;
  
  const VarialbeGradient & _pressure_gradient;
 
  const MaterialProperty<Real> & _permeability;
  const MaterialProperty<Real> & _viscosity;
};

#endif
