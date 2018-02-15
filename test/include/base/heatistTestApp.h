//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef HEATISTTESTAPP_H
#define HEATISTTESTAPP_H

#include "MooseApp.h"

class heatistTestApp;

template <>
InputParameters validParams<heatistTestApp>();

class heatistTestApp : public MooseApp
{
public:
  heatistTestApp(InputParameters parameters);
  virtual ~heatistTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* HEATISTTESTAPP_H */
