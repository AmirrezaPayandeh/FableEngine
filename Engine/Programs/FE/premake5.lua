project "FE"
	location (ProjectsLocation)
	kind "SharedLib"
	language "C++"

	targetdir (TargetDir)
	objdir (ObjDir)

	pchheader "FablePCH.h"
	pchsource (SourceDir .. "Fable/Core/FablePCH.cpp")

	files
	{
		EngineDir .. "**" -- includes Source and Shaders
	}

	excludes
	{
		ProgramsSourceDir .. "**",
		BinariesDir .. "**",
		IntermediateDir .. "**",
		ExtrasDir .. "**"
	}

	includedirs
	{
		--[[ ThirdParty includes ]]
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",

		--[[ Engine includes ]]
		"%{IncludeDir.Fable}",
		"%{IncludeDir.FableCore}",
		"%{IncludeDir.FableApplicationCore}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FB_PLATFORM_WINDOWS",
			"FB_BUILD_DLL"
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
