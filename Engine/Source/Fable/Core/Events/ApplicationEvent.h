#pragma once

#include "Event.h"

FABLE_NAMESPACE_BEGIN

class CORE_API WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(uint32 width, uint32 height)
		: m_Width(width), m_Height(height) {}

	inline uint32 GetWidth() const { return m_Width; }
	inline uint32 GetHeight() const { return m_Height; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowReszieEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
private:
	uint32 m_Width, m_Height;
};

class CORE_API WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowCloseEvent";
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class CORE_API AppTickEvent : public Event
{
public:
	AppTickEvent() {}

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class CORE_API AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() {}

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class CORE_API AppRenderEvent : public Event
{
public:
	AppRenderEvent() {}

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


FABLE_NAMESPACE_END
