project "Sandbox"
	location (ProjectsLocation)
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

		defines
		{
			"FB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines
		{
			"FB_DEBUG"
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		defines
		{
			"FB_RELEASE"
		}

	filter "configurations:Distribution"
		runtime "Release"
		optimize "on"
		defines
		{
			"FB_DIST"
		}
