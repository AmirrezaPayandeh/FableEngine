#include "FablePCH.h"
#include "WindowsInput.h"

#include "ApplicationCore.h"

#include <GLFW/glfw3.h>

FABLE_NAMESPACE_BEGIN

Input* Input::s_Instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int keycode) const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(ApplicationCore::Get().GetWindow().GetNativeWindow());
	int state = glfwGetKey(window, keycode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(int button) const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(ApplicationCore::Get().GetWindow().GetNativeWindow());
	int state = glfwGetMouseButton(window, button);
	return state == GLFW_PRESS;
}

std::pair<float, float> WindowsInput::GetMousePositionImpl() const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(ApplicationCore::Get().GetWindow().GetNativeWindow());
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	return { (float)xpos, (float)ypos };
}

float WindowsInput::GetMouseXImpl() const
{
	auto[x, y] = GetMousePositionImpl();
	return x;
}

float WindowsInput::GetMouseYImpl() const
{
	auto [x, y] = GetMousePositionImpl();
	return y;
}


FABLE_NAMESPACE_END

