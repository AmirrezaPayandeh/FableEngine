project "GLFW"
	location (ProjectsLocation)
	kind "StaticLib"
	language "C"
	staticruntime "On"

	targetdir (TargetDir)
	objdir (ObjDir)

	files
	{
		ProgramsSourceDir .. "GLFW/include/GLFW/glfw3.h",
		ProgramsSourceDir .. "GLFW/include/GLFW/glfw3native.h",
		ProgramsSourceDir .. "GLFW/src/glfw_config.h",
		ProgramsSourceDir .. "GLFW/src/context.c",
		ProgramsSourceDir .. "GLFW/src/init.c",
		ProgramsSourceDir .. "GLFW/src/input.c",
		ProgramsSourceDir .. "GLFW/src/monitor.c",
		ProgramsSourceDir .. "GLFW/src/vulkan.c",
		ProgramsSourceDir .. "GLFW/src/window.c"
	}

	filter "system:windows"
		systemversion "latest"

		files
		{
			ProgramsSourceDir .. "GLFW/src/win32_init.c",
			ProgramsSourceDir .. "GLFW/src/win32_joystick.c",
			ProgramsSourceDir .. "GLFW/src/win32_monitor.c",
			ProgramsSourceDir .. "GLFW/src/win32_time.c",
			ProgramsSourceDir .. "GLFW/src/win32_thread.c",
			ProgramsSourceDir .. "GLFW/src/win32_window.c",
			ProgramsSourceDir .. "GLFW/src/wgl_context.c",
			ProgramsSourceDir .. "GLFW/src/egl_context.c",
			ProgramsSourceDir .. "GLFW/src/osmesa_context.c"
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
			ProgramsSourceDir .. "GLFW/src/x11_init.c",
			ProgramsSourceDir .. "GLFW/src/x11_monitor.c",
			ProgramsSourceDir .. "GLFW/src/x11_window.c",
			ProgramsSourceDir .. "GLFW/src/xkb_unicode.c",
			ProgramsSourceDir .. "GLFW/src/posix_time.c",
			ProgramsSourceDir .. "GLFW/src/posix_thread.c",
			ProgramsSourceDir .. "GLFW/src/glx_context.c",
			ProgramsSourceDir .. "GLFW/src/egl_context.c",
			ProgramsSourceDir .. "GLFW/src/osmesa_context.c",
			ProgramsSourceDir .. "GLFW/src/linux_joystick.c"
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
		
	filter "configurations:Distribution"
		runtime "Release"
		optimize "on"
