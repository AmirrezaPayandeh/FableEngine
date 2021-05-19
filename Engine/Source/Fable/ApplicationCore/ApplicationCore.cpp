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
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_Window->OnUpdate();
	}
}

void ApplicationCore::OnEvent(Event& e)
{
	EventDispather dispather(e);
	dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

	FB_LOG(Engine, Trace, "{0}", e);

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
	{
		(*--it)->OnEvent(e);
		if (e.IsHandled())
			break;
	}
}

void ApplicationCore::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void ApplicationCore::PushOverlay(Layer* overlay)
{
	m_LayerStack.PopOverlay(overlay);
}

bool ApplicationCore::OnWindowClosed(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}


FABLE_NAMESPACE_END
