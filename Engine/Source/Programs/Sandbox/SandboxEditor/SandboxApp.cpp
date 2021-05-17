#include "SandboxApp.h"

SandboxApp::SandboxApp()
{
}

SandboxApp::~SandboxApp()
{
}

Fable::Application* Fable::CreateApplication()
{
	return new SandboxApp();
}
