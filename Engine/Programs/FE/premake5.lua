project "FE"
	location (ProjectsLocation)
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir (TargetDir)
	objdir (ObjDir)

	pchheader "FablePCH.h"
	pchsource (SourceDir .. "Fable/Core/Misc/FablePCH.cpp")

	files
	{
		EngineDir .. "**" -- includes Source and Shaders
	}

	excludes
	{
		ProgramsSourceDir .. "**",
		BinariesDir .. "**",
		IntermediateDir .. "**",
		ExtrasDir .. "**",

		ThirdPartySourceDir .. "**.c",
		ThirdPartySourceDir .. "**.cpp"
	}

	includedirs
	{
		-- [[ ThirdParty includes ]]
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",

		-- [[ Engine includes ]]
		"%{IncludeDir.Fable}",
		"%{IncludeDir.FableCore}",
		"%{IncludeDir.FableCore}/Events",
		"%{IncludeDir.FableCore}/GenericPlatform",
		"%{IncludeDir.FableCore}/Input",
		"%{IncludeDir.FableCore}/Layer",
		"%{IncludeDir.FableCore}/Logging",
		"%{IncludeDir.FableCore}/Misc",

		"%{IncludeDir.FableApplicationCore}",
		"%{IncludeDir.FableApplicationCore}/GenericWindow",
		"%{IncludeDir.FableApplicationCore}/OpenGL",
		"%{IncludeDir.FableApplicationCore}/Windows",

		"%{IncludeDir.FableImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"FB_PLATFORM_WINDOWS",
			"FB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
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