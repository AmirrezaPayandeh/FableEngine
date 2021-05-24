#pragma once

#include "GenericWindow/GenericWindow.h"

#include "Core/CoreMinimal.h"
#include "Core/Layer/LayerStack.h"
#include "Core/Events/ApplicationEvent.h"

#include "Renderer/Shader.h"

#include "ImGui/ImGuiLayer.h"

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
	bool OnWindowClosed(WindowCloseEvent& e);

private:
	static ApplicationCore* s_Instance;

private:
	bool m_Running = true;
	std::unique_ptr<GenericWindow> m_Window;
	LayerStack m_LayerStack;
	ImGuiLayer* m_ImGuiLayer;

	uint32 m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	std::unique_ptr<Shader> m_Shader;
};

// To be defined in CLIENT
ApplicationCore* CreateApplication();

FABLE_NAMESPACE_END
