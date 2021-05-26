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

	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	float vertecies[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	m_VertexBuffer.reset(VertexBuffer::Create(sizeof(vertecies), vertecies));
	m_VertexBuffer->Bind();

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	uint32 indecies[] = { 0, 1, 2 };
	m_IndexBuffer.reset(IndexBuffer::Create(sizeof(indecies) / sizeof(uint32), indecies));

	std::string vertextSrc = R"(
		#version 330 core

		layout(location = 0) in vec3 a_Position;		

		out vec3 v_Position;
		
		void main()
		{
			v_Position = a_Position;
			gl_Position = vec4(a_Position, 1.0);
		}
	)";

	std::string fragmentSrc = R"(
		#version 330 core

		layout(location = 0) out vec4 color;		

		in vec3 v_Position;

		void main()
		{
			color = vec4(v_Position * 0.5 + 0.5, 1.0);
		}
	)";

	m_Shader.reset(new Shader(vertextSrc, fragmentSrc));
}

ApplicationCore::~ApplicationCore()
{
}

void ApplicationCore::Run()
{
	while (m_Running)
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Shader->Bind();
		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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
}

void ApplicationCore::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
}

bool ApplicationCore::OnWindowClosed(WindowCloseEvent& event)
{
	m_Running = false;
	return true;
}

FABLE_NAMESPACE_END
