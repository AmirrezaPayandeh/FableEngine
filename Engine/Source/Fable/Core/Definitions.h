#pragma once

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#define FABLE_NAMESPACE_BEGIN namespace Fable {
#define FABLE_NAMESPACE_END }

#define SPDLOG_EOL ""

#define BIT(x) (1 << x)

#if FB_PLATFORM_WINDOWS
	#if FB_BUILD_DLL
		#define FABLE_API DLLEXPORT
	#else
		#define FABLE_API DLLIMPORT
	#endif
#else
	#error Fable only supports windows!
#endif
