#include "FablePCH.h"
#include "ApplicationCore.h"

// TEMPORARY
#include <Glad/glad.h>

FABLE_NAMESPACE_BEGIN

ApplicationCore* ApplicationCore::s_Instance = nullptr;

ApplicationCore::ApplicationCore()
{
	FB_ASSERT(Engine, !s_Instance, "Application already exists!");
	s_Instance = this;

	m_Window = std::unique_ptr<GenericWindow>(GenericWindow::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(ApplicationCore::OnEvent));

	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);
}

ApplicationCore::~ApplicationCore()
{
}

void ApplicationCore::Run()
{
	while (m_Running)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_ImGuiLayer->Begin();
		for (Layer* layer : m_LayerStack)
			layer->OnImGuiRender();
		m_ImGuiLayer->End();

		m_Window->OnUpdate();
	}
}

void ApplicationCore::OnEvent(Event& event)
{
	EventDispather dispather(event);
	dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(ApplicationCore::OnWindowClosed));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
	{
		(*--it)->OnEvent(event);
		if (event.IsHandled())
			break;
	}
}

void ApplicationCore::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void ApplicationCore::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
	overlay->OnAttach();
}

bool ApplicationCore::OnWindowClosed(WindowCloseEvent& event)
{
	m_Running = false;
	return true;
}

FABLE_NAMESPACE_END
