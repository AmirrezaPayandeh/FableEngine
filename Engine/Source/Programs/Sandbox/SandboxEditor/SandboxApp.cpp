#include "SandboxApp.h"

SandboxApp::SandboxApp()
{
}

SandboxApp::~SandboxApp()
{
}

Fable::ApplicationCore* Fable::CreateApplication()
{
	return new SandboxApp();
}
