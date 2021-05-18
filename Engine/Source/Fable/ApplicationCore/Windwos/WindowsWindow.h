#pragma once

#include "GenericWindow/GenericWindow.h"

#include <GLFW/glfw3.h>

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
	inline void SetEventCallBack(const EventCallBackFn& callback) override { m_Data.EventCallBack = callback; }
	void SetVSync(bool enabled) override;
	bool IsVSync() const override;
private:
	virtual void Init(const WindowProps& props);
	virtual void ShutDown();
private:
	GLFWwindow* m_Window;

	struct WindowData
	{
		std::string Title;
		uint32 Width, Height;
		bool VSync;

		EventCallBackFn EventCallBack;
	};

	WindowData m_Data;
};

FABLE_NAMESPACE_END