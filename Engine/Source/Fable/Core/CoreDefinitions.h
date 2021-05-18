#pragma once

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#define FABLE_NAMESPACE_BEGIN namespace Fable {
#define FABLE_NAMESPACE_END }


#define BIT(x) (1 << x)


#if FB_BUILD_DLL
	#define FABLE_API DLLEXPORT
	#define CORE_API DLLEXPORT
	#define APPLICATIONCORE_API DLLEXPORT
#else
	#define FABLE_API DLLIMPORT
	#define CORE_API DLLIMPORT
	#define APPLICATIONCORE_API DLLIMPORT
#endif


#ifndef FB_PLATFORM_WINDOWS
	#error Fable only supports windows!
#endif


#if FB_DEBUG
	#if FB_PLATFORM_WINDOWS
		#define DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif

	#define FB_ENABLE_ASSERTS
#else
	#define DEBUGBREAK()
#endif

