#pragma once

#include "Core/Misc/CoreDefinitions.h"
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

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnImGuiRender() override;

	void Begin();
	void End();
private:
	float m_Time = 0.0f;
};

FABLE_NAMESPACE_END
