#include "FablePCH.h"
#include "ApplicationCore.h"

FABLE_NAMESPACE_BEGIN

#define BIND_EVENT_FN(x) std::bind(&ApplicationCore::x, this, std::placeholders::_1)

ApplicationCore::ApplicationCore()
{
	m_Window = std::unique_ptr<GenericWindow>(GenericWindow::Create());
	m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
}

ApplicationCore::~ApplicationCore()
{
}

void ApplicationCore::Run()
{
	while (m_Running)
	{
		m_Window->OnUpdate();
	}
}

void ApplicationCore::OnEvent(Event& e)
{
	EventDispather dispather(e);
	dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

	FB_LOG(Engine, Trace, "{0}", e);
}

bool ApplicationCore::OnWindowClosed(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}


FABLE_NAMESPACE_END
