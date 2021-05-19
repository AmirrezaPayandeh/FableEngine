#include "FablePCH.h"
#include "WindowsWindow.h"

#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

FABLE_NAMESPACE_BEGIN

static bool s_GLFWInitialized = false;

static void GLFWErrorCallBack(int error, const char* description)
{
	FB_LOG(Engine, Error, "GLFW Error ({0}): {1}", error, description);
}

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
		glfwSetErrorCallback(GLFWErrorCallBack);
		s_GLFWInitialized = true;
	}

	m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVSync(true);

	// Set GLFW callbacks
	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;

		WindowResizeEvent event(width, height);
		data.EventCallBack(event);
	});

	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.EventCallBack(event);
	});

	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallBack(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallBack(event);
				break;
			}
		}
	});

	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallBack(event);
				break;
			}
		}
	});

	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.EventCallBack(event);
	});

	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPosition, double yPosition)
	{
		WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseMoveEvent event((float)xPosition, (float)yPosition);
		data.EventCallBack(event);
	});
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
