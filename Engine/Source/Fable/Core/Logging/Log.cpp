#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

FABLE_NAMESPACE_BEGIN

std::shared_ptr<spdlog::logger> Log::s_Logger;

void Log::Init()
{
	s_Logger = spdlog::stdout_color_mt("Logger");
	s_Logger->set_level(spdlog::level::level_enum::trace);
}

FABLE_NAMESPACE_END
