#include "SandboxApp.h"

class ExampleLayer : public Fable::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FB_LOG(App, Info, "ExampleLayer::Update");
	}

	void OnEvent(Fable::Event& event) override
	{
		FB_LOG(App, Trace, "{0}", event);
	}
};

SandboxApp::SandboxApp()
{
	PushLayer(new ExampleLayer());
}

SandboxApp::~SandboxApp()
{
}

Fable::ApplicationCore* Fable::CreateApplication()
{
	return new SandboxApp();
}
