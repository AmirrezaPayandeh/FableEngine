#pragma once

#include "CoreMinimal.h"
#include "Events/Event.h"

FABLE_NAMESPACE_BEGIN

struct WindowProps
{
	std::string Title;
	uint32 Width, Height;

	WindowProps(const std::string& title = "Fable Engine", uint32 width = 1280, uint32 height = 720)
		: Title(title), Width(width), Height(height)
	{
	}
};

// Interface representig a desktop system based window
class APPLICATIONCORE_API GenericWindow
{
public:
	using EventCallBackFn = std::function<void(Event&)>;

	virtual ~GenericWindow() {}

	virtual void OnUpdate() = 0;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
	virtual void SetVSync(bool enabled) = 0;
	virtual bool IsVSync() const = 0;

	static GenericWindow* Create(const WindowProps& props = WindowProps());
};

FABLE_NAMESPACE_END
