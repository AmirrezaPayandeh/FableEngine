#pragma once

#include "Event.h"

FABLE_NAMESPACE_BEGIN

class CORE_API MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(float x, float y)
		: m_MouseX(x), m_MouseY(y) {}

	inline float GetX() const { return m_MouseX; }
	inline float GetY() const { return m_MouseY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	float m_MouseX, m_MouseY;
};

class CORE_API MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(float xOffset, float yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) {}

	inline float GetXOffset() const { return m_XOffset; }
	inline float GetYOffset() const { return m_YOffset; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
	}

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	float m_XOffset, m_YOffset;
};

class CORE_API MouseButtonEvent : public Event
{
public:
	inline int32 GetMouseButton() const { return m_Button; }

	EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput)
protected:
	MouseButtonEvent(int32 button)
		: m_Button(button) {}

	int32 m_Button;
};


class CORE_API MousePressedEvent : public MouseButtonEvent
{
public:
	MousePressedEvent(int32 button)
		: MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class CORE_API MouseReleasedEvent : public MouseButtonEvent
{
public:
	MouseReleasedEvent(int32 button)
		: MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

FABLE_NAMESPACE_END
