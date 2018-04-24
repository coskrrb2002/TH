#ifndef HEATCONVECTION_H
#define HEATCONVECTION_H

#include "Kernel.h"

class HeatConvection;

template <>
InputParameters validParams<HeatConvection>();

class HeatConvection : public Kernel
{
public: HeatConvection(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;
  const VariableGradient & _pressure_gradient;

  unsigned int _pressure_var;

  const MaterialProperty<Real> & _permeability;
  const MaterialProperty<Real> & _porosity;
  const MaterialProperty<Real> & _viscosity;
  const MaterialProperty<Real> & _density;
  const MaterialProperty<Real> & _heat_capacity;






};

#endif
