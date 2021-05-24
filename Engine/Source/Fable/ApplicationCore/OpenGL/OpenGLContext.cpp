#include "FablePCH.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>

FABLE_NAMESPACE_BEGIN

OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	FB_ASSERT(m_WindowHandle, "Window handle is null!");
}

void OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	FB_ASSERT(Engine, "Faild to initialize Glad!");

	FB_LOG(Engine, Info, "OpenGL Info:");
	FB_LOG(Engine, Info, "  Vendor: {0}", glGetString(GL_VENDOR));
	FB_LOG(Engine, Info, "  Renderer: {0}", glGetString(GL_RENDERER));
	FB_LOG(Engine, Info, "  Version: {0}", glGetString(GL_VERSION));
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}

FABLE_NAMESPACE_END
