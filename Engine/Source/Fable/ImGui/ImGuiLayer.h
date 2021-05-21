#pragma once

#include "Core/CoreDefinitions.h"
#include "Core/Layer/Layer.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/ApplicationEvent.h"

FABLE_NAMESPACE_BEGIN

class IMGUI_API ImGuiLayer : public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	void OnAttach();
	void OnDetach();
	void OnUpdate();
	void OnEvent(Event& event);
private:
	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
	bool OnMouseMovedEvent(MouseMovedEvent& event);
	bool OnMouseScrolledEvent(MouseScrolledEvent& event);
	bool OnKeyPressedEvent(KeyPressedEvent& event);
	bool OnKeyReleasedEvent(KeyReleasedEvent& event);
	bool OnKeyTypedEvent(KeyTypedEvent& event);
	bool OnWindowResizeEvent(WindowResizeEvent& event);
private:
	float m_Time = 0.0f;
};

FABLE_NAMESPACE_END
