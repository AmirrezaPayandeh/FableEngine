project "GLFW"
	location "%{wks.location}/Engine/Intermediate/ProjectFiles"
	kind "StaticLib"
	language "C"

	targetdir ("%{wks.location}/Engine/Binaries/%{cfg.platform}")
	objdir ("%{wks.location}/Engine/Intermediate/Build/%{cfg.platform}/%{prj.name}")

	files
	{
		"%{wks.location}/Engine/Source/Programs/GLFW/include/GLFW/glfw3.h",
		"%{wks.location}/Engine/Source/Programs/GLFW/include/GLFW/glfw3native.h",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/glfw_config.h",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/context.c",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/init.c",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/input.c",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/monitor.c",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/vulkan.c",
		"%{wks.location}/Engine/Source/Programs/GLFW/src/window.c"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_init.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_joystick.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_monitor.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_time.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_thread.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/win32_window.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/wgl_context.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/egl_context.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/osmesa_context.c"
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "system:linux"
		pic "On"

		systemversion "latest"
		
		files
		{
			"%{wks.location}/Engine/Source/Programs/GLFW/src/x11_init.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/x11_monitor.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/x11_window.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/xkb_unicode.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/posix_time.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/posix_thread.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/glx_context.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/egl_context.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/osmesa_context.c",
			"%{wks.location}/Engine/Source/Programs/GLFW/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"
