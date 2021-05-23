project "Sandbox"
	location (ProjectsLocation)
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir (TargetDir)
	objdir (ObjDir)

	files
	{
		ProgramsSourceDir .. "Sandbox/**"
	}

	includedirs
	{
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.Fable}",
		"%{IncludeDir.FableCore}"
	}

	links
	{
		"FE"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"FB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		defines
		{
			"FB_DEBUG"
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		defines
		{
			"FB_RELEASE"
		}

	filter "configurations:Distribution"
		runtime "Release"
		optimize "On"
		defines
		{
			"FB_DIST"
		}
