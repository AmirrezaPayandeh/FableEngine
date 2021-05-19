#pragma once

#include "Log.h"

#define FB_LOG_MESSAGE(Level, ...) \
{ \
	Fable::Log::LogMessage(Fable::LogLevel::Level, __VA_ARGS__); \
}

#define FB_LOG(CategoryName, Level, ...) \
{ \
	Fable::Log::GetLogger()->set_pattern("%^[%T] %v: %$"); \
	FB_LOG_MESSAGE(Level, #CategoryName) \
	Fable::Log::GetLogger()->set_pattern("%^%v\n%$"); \
	FB_LOG_MESSAGE(Level, __VA_ARGS__) \
}
