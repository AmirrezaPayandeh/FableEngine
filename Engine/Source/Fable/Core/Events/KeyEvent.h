#pragma once

#include "Event.h"

FABLE_NAMESPACE_BEGIN

class CORE_API KeyEvent : public Event
{
public:
	inline int32 GetKeyCode() const { return m_KeyCode; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
protected:
	KeyEvent(int32 keycode)
		: m_KeyCode(keycode) {}

	int32 m_KeyCode;
};

class CORE_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int32 keycode, int32 repeatCount)
		: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

	inline int32 GetRepeatCount() const { return m_RepeatCount; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)
private:
	int32 m_RepeatCount;
};

class CORE_API KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int32 keycode)
		: KeyEvent(keycode)
	{
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};

class CORE_API KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(int32 keycode)
		: KeyEvent(keycode)
	{
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_KeyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyTyped)
};

FABLE_NAMESPACE_END
