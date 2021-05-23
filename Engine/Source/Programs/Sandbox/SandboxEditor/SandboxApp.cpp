#include "SandboxApp.h"

#include "imgui.h"

class ExampleLayer : public Fable::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnUpdate() override
	{
		//FB_LOG(App, Info, "ExampleLayer::Update");
	}

	virtual void OnEvent(Fable::Event& event) override
	{
		//FB_LOG(App, Trace, "{0}", event);
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
