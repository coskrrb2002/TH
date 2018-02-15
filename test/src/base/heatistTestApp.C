//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "heatistTestApp.h"
#include "heatistApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<heatistTestApp>()
{
  InputParameters params = validParams<heatistApp>();
  return params;
}

heatistTestApp::heatistTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  heatistApp::registerObjectDepends(_factory);
  heatistApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  heatistApp::associateSyntaxDepends(_syntax, _action_factory);
  heatistApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  heatistApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    heatistTestApp::registerObjects(_factory);
    heatistTestApp::associateSyntax(_syntax, _action_factory);
    heatistTestApp::registerExecFlags(_factory);
  }
}

heatistTestApp::~heatistTestApp() {}

void
heatistTestApp::registerApps()
{
  registerApp(heatistApp);
  registerApp(heatistTestApp);
}

void
heatistTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
heatistTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
heatistTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
heatistTestApp__registerApps()
{
  heatistTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
heatistTestApp__registerObjects(Factory & factory)
{
  heatistTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
heatistTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  heatistTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
heatistTestApp__registerExecFlags(Factory & factory)
{
  heatistTestApp::registerExecFlags(factory);
}
