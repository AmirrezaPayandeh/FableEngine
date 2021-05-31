#include "FablePCH.h"
#include "ApplicationCore.h"

// TEMPORARY
#include <Glad/glad.h>

FABLE_NAMESPACE_BEGIN

ApplicationCore* ApplicationCore::s_Instance = nullptr;

static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
{
	switch (type)
	{
		case ShaderDataType::Float:     return GL_FLOAT;
		case ShaderDataType::Float2:    return GL_FLOAT;
		case ShaderDataType::Float3:    return GL_FLOAT;
		case ShaderDataType::Float4:    return GL_FLOAT;
		case ShaderDataType::Mat3:      return GL_FLOAT;
		case ShaderDataType::Mat4:      return GL_FLOAT;
		case ShaderDataType::Int:       return GL_INT;
		case ShaderDataType::Int2:      return GL_INT;
		case ShaderDataType::Int3:      return GL_INT;
		case ShaderDataType::Int4:      return GL_INT;
		case ShaderDataType::Bool:      return GL_BOOL;
	}

	FB_ASSERT(Engine, false, "Unkown Shader Data Type!");
	return 0;
}

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

	float vertecies[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};

	m_VertexBuffer.reset(VertexBuffer::Create(sizeof(vertecies), vertecies));
	m_VertexBuffer->Bind();

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

	{
		BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position", false },
			{ ShaderDataType::Float4, "a_Color", false }
		};

		m_VertexBuffer->SetLayout(layout);
	}

	const auto& layout = m_VertexBuffer->GetLayout();
	uint32 index = 0;
	for (const auto& element : layout)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index,
			element.GetComponentCount(),
			ShaderDataTypeToOpenGLBaseType(element.Type),
			element.Normalized ? GL_TRUE : GL_FALSE,
			layout.GetStride(),
			(const void*)element.Offset);
		index++;
	}

	uint32 indecies[] = { 0, 1, 2 };
	m_IndexBuffer.reset(IndexBuffer::Create(sizeof(indecies) / sizeof(uint32), indecies));

	std::string vertextSrc = R"(
		#version 330 core

		layout(location = 0) in vec3 a_Position;		
		layout(location = 1) in vec4 a_Color;		

		out vec3 v_Position;
		out vec4 v_Color;
		
		void main()
		{
			v_Position = a_Position;
			v_Color = a_Color;
			gl_Position = vec4(a_Position, 1.0);
		}
	)";

	std::string fragmentSrc = R"(
		#version 330 core

		layout(location = 0) out vec4 color;		

		in vec3 v_Position;
		in vec4 v_Color;

		void main()
		{
			color = vec4(v_Position * 0.5 + 0.5, 1.0);
			color = v_Color;
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
