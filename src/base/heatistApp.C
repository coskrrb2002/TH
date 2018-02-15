#include "heatistApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<heatistApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

heatistApp::heatistApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  heatistApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  heatistApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  heatistApp::registerExecFlags(_factory);
}

heatistApp::~heatistApp() {}

void
heatistApp::registerApps()
{
  registerApp(heatistApp);
}

void
heatistApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
heatistApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
heatistApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
heatistApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
heatistApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
heatistApp__registerApps()
{
  heatistApp::registerApps();
}

extern "C" void
heatistApp__registerObjects(Factory & factory)
{
  heatistApp::registerObjects(factory);
}

extern "C" void
heatistApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  heatistApp::associateSyntax(syntax, action_factory);
}

extern "C" void
heatistApp__registerExecFlags(Factory & factory)
{
  heatistApp::registerExecFlags(factory);
}
