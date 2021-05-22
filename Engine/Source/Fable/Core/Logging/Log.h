#pragma once

#include "Misc/CoreDefinitions.h"
#include "LogLevel.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

FABLE_NAMESPACE_BEGIN

class CORE_API Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

	template<typename FormatString, typename... Args>
	static void LogMessage(LogLevel level, const FormatString& fmt, Args &&...args)
	{
		switch (level)
		{
		case LogLevel::Fatal:
			::Fable::Log::GetLogger()->critical(fmt, args...);
			break;
		case LogLevel::Error:
			::Fable::Log::GetLogger()->error(fmt, args...);
			break;
		case LogLevel::Warn:
			::Fable::Log::GetLogger()->warn(fmt, args...);
			break;
		case LogLevel::Info:
			::Fable::Log::GetLogger()->info(fmt, args...);
			break;
		case LogLevel::Trace:
			::Fable::Log::GetLogger()->trace(fmt, args...);
			break;
		case LogLevel::All:
			::Fable::Log::GetLogger()->trace(fmt, args...);
			break;
		default:
			break;
		}
	}
private:
	static std::shared_ptr<spdlog::logger> s_Logger;
};

FABLE_NAMESPACE_END
