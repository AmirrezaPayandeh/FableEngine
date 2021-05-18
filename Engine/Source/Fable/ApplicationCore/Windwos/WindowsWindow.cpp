#include "FablePCH.h"
#include "WindowsWindow.h"

FABLE_NAMESPACE_BEGIN

static bool s_GLFWInitialized = false;

GenericWindow* GenericWindow::Create(const WindowProps& props)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps& props)
{
	Init(props);
}

WindowsWindow::~WindowsWindow()
{
	ShutDown();
}

void WindowsWindow::Init(const WindowProps& props)
{
	m_Data.Title = props.Title;
	m_Data.Width = props.Width;
	m_Data.Height = props.Height;

	FB_LOG(Engine, Info, "Creating Window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

	if (!s_GLFWInitialized)
	{
		int success = glfwInit();
		FB_ASSERT(Engine, success, "Could not initialize GLFW!");

		s_GLFWInitialized = true;
	}

	m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVSync(true);
}

void WindowsWindow::ShutDown()
{
	glfwDestroyWindow(m_Window);
}

void WindowsWindow::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void WindowsWindow::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_Data.VSync = enabled;
}

bool WindowsWindow::IsVSync() const
{
	return m_Data.VSync;
}

FABLE_NAMESPACE_END
