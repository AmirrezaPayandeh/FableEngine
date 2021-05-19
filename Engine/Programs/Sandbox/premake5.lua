project "Sandbox"
	location (ProjectsLocation)
	kind "ConsoleApp"
	language "C++"

	targetdir (TargetDir)
	objdir (ObjDir)

	files
	{
		ProgramsSourceDir .. "Sandbox/**"
	}

	includedirs
	{
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.Fable}"
	}

	links
	{
		"FE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		symbols "On"
		defines
		{
			"FB_DEBUG"
		}

	filter "configurations:Release"
		optimize "On"
		defines
		{
			"FB_RELEASE"
		}

	filter "configurations:Distribution"
		optimize "On"
		defines
		{
			"FB_DIST"
		}
