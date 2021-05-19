#pragma once

#include "Core/CoreMinimal.h"
#include "Core/Layer/LayerStack.h"
#include "Core/Events/ApplicationEvent.h"
#include "ApplicationCore/GenericWindow/GenericWindow.h"

FABLE_NAMESPACE_BEGIN

class APPLICATIONCORE_API ApplicationCore
{
public:
	ApplicationCore();
	virtual ~ApplicationCore();

	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);
private:
	bool OnWindowClosed(WindowCloseEvent& e);

	std::unique_ptr<GenericWindow> m_Window;
	bool m_Running = true;
	LayerStack m_LayerStack;
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
