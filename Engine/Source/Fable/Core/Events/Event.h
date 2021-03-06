#pragma once

#include "CoreMinimal.h"

FABLE_NAMESPACE_BEGIN

// Events in Fable are currently blocking, meaning that when an event occurs
// it immediately must be dealth with right then and there. For the future,
// we will buffer events and process them during the update stage.

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication     = BIT(0),
	EventCategoryInput           = BIT(1),
	EventCategoryKeyboard        = BIT(2),
	EventCategoryMouse           = BIT(3),
	EventCategoryMouseButton     = BIT(4)
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
                               virtual EventType GetEventType() const override { return GetStaticType(); } \
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int32 GetCategoryFlags() const { return category; }

class CORE_API Event
{
	friend class EventDispather;
public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int32 GetCategoryFlags() const = 0;

	virtual inline bool IsHandled() const final { return m_Handled; }
	virtual std::string ToString() const { return GetName(); }

	inline bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}
protected:
	bool m_Handled = false;
};

class EventDispather
{
	template<typename T>
	using EventFn = std::function<bool(T&)>;
public:
	EventDispather(Event& event)
		: m_Event(event)
	{
	}

	template<typename T>
	bool Dispatch(EventFn<T> func)
	{
		if (m_Event.GetEventType() == T::GetStaticType())
		{
			m_Event.m_Handled = func(*(T*)&m_Event);
			return true;
		}
		return false;
	}
private:
	Event& m_Event;
};

inline std::ostream& operator<<(std::ostream& stream, const Event& event)
{
	return stream << event.ToString();
}

FABLE_NAMESPACE_END