#pragma once

#include "GenericWindow/GenericWindow.h"

#include "Core/CoreMinimal.h"
#include "Core/Layer/LayerStack.h"
#include "Core/Events/ApplicationEvent.h"

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

	inline static ApplicationCore& Get() { return *s_Instance; }
	inline GenericWindow& GetWindow() const { return *m_Window; }
private:
	static ApplicationCore* s_Instance;
	bool OnWindowClosed(WindowCloseEvent& e);

	std::unique_ptr<GenericWindow> m_Window;
	bool m_Running = true;
	LayerStack m_LayerStack;
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
