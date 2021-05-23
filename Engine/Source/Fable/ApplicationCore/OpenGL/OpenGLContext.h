#pragma once

#include "Core/Misc/CoreDefinitions.h"
#include "Renderer/RendererContext.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

FABLE_NAMESPACE_BEGIN

class APPLICATIONCORE_API OpenGLContext : public RendererContext
{
public:
	OpenGLContext(GLFWwindow* windowHandle);

	virtual void Init() override;
	virtual void SwapBuffers() override;
private:
	GLFWwindow* m_WindowHandle;
};

FABLE_NAMESPACE_END
