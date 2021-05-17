#pragma once

#include "Core/Core.h"
#include "LogLevel.h"
#include "LogMacros.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

FABLE_NAMESPACE_BEGIN

class FABLE_API Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
private:
	static std::shared_ptr<spdlog::logger> s_Logger;
};

FABLE_NAMESPACE_END
