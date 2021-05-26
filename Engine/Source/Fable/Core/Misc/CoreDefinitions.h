#pragma once

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#define FABLE_NAMESPACE_BEGIN namespace Fable {
#define FABLE_NAMESPACE_END }


#define BIT(x) (1 << x)

#define BIND_EVENT_FN(Func) std::bind(&Func, this, std::placeholders::_1)


#ifdef FB_DYNAMIC_LINK
	#if FB_BUILD_DLL
		#define FABLE_API DLLEXPORT
		#define CORE_API DLLEXPORT
		#define APPLICATIONCORE_API DLLEXPORT
		#define IMGUI_API DLLEXPORT
		#define RENDERER_API DLLEXPORT
		#define OPENGLRENDERER_API DLLEXPORT
	#else
		#define FABLE_API DLLIMPORT
		#define CORE_API DLLIMPORT
		#define APPLICATIONCORE_API DLLIMPORT
		#define IMGUI_API DLLIMPORT
		#define RENDERER_API DLLIMPORT
		#define OPENGLRENDERER_API DLLIMPORT
	#endif
#else
	#define FABLE_API
	#define CORE_API
	#define APPLICATIONCORE_API
	#define IMGUI_API
	#define RENDERER_API
	#define OPENGLRENDERER_API
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

