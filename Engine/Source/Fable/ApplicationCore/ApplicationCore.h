#pragma once

#include "Core/CoreMinimal.h"
#include "GenericWindow/GenericWindow.h"
#include "Events/ApplicationEvent.h"

FABLE_NAMESPACE_BEGIN

class APPLICATIONCORE_API ApplicationCore
{
public:
	ApplicationCore();
	virtual ~ApplicationCore();

	void Run();

	void OnEvent(Event& e);
private:
	bool OnWindowClosed(WindowCloseEvent& e);

	std::unique_ptr<GenericWindow> m_Window;
	bool m_Running = true;
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
