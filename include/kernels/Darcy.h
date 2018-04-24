#ifndef DARCY_H
#define DARCY_H

#include "Kernel.h"

class Darcy;

template <>
InputParameters validParams<Darcy>();

class Darcy : public Kernel
{
public:
  Darcy(const InputParameters & parameters);


protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

const MaterialProperty<Real> & _permeability;
const MaterialProperty<Real> & _viscosity;
};

#endif
