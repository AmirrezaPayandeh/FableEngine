#pragma once

#include "Log.h"

#define FB_LOG_MESSAGE(Level, ...) \
{ \
	switch (LogLevel::Level) \
	{ \
		case LogLevel::Fatal: \
			::Fable::Log::GetLogger()->critical(__VA_ARGS__); \
			break; \
		case LogLevel::Error: \
			::Fable::Log::GetLogger()->error(__VA_ARGS__); \
			break; \
		case LogLevel::Warn: \
			::Fable::Log::GetLogger()->warn(__VA_ARGS__); \
			break; \
		case LogLevel::Info: \
			::Fable::Log::GetLogger()->info(__VA_ARGS__); \
			break; \
		case LogLevel::Trace: \
			::Fable::Log::GetLogger()->trace(__VA_ARGS__); \
			break; \
		case LogLevel::All: \
			::Fable::Log::GetLogger()->trace(__VA_ARGS__); \
			break; \
		default: \
			break; \
	} \
}

#define FB_LOG(CategoryName, Level, ...) \
{ \
	static_assert((LogLevel::Level & LogLevel::LevelMask) < LogLevel::NumLevel && LogLevel::Level > 0, "Level must be constant and in range."); \
	Fable::Log::GetLogger()->set_pattern("%^[%T] %v: %$"); \
	FB_LOG_MESSAGE(Level, #CategoryName) \
	Fable::Log::GetLogger()->set_pattern("%^%v\n%$"); \
	FB_LOG_MESSAGE(Level, __VA_ARGS__) \
}
