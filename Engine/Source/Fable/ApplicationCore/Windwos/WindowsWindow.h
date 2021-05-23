#pragma once

#include "GenericWindow/GenericWindow.h"
#include "OpenGL/OpenGLContext.h"


FABLE_NAMESPACE_BEGIN

class APPLICATIONCORE_API WindowsWindow : public GenericWindow
{
public:
	WindowsWindow(const WindowProps& props);
	virtual ~WindowsWindow();

	void OnUpdate() override;

	inline uint32 GetWidth() const override { return m_Data.Width; }
	inline uint32 GetHeight() const override { return m_Data.Height; }

	// Window attributes
	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
	void SetVSync(bool enabled) override;
	bool IsVSync() const override;

	inline virtual void* GetNativeWindow() const { return m_Window; }
private:
	virtual void Init(const WindowProps& props);
	virtual void ShutDown();
private:
	GLFWwindow* m_Window;
	RendererContext* m_Context;

	struct WindowData
	{
		std::string Title;
		uint32 Width, Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	WindowData m_Data;
};

FABLE_NAMESPACE_END