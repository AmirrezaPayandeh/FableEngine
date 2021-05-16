project "FE"
	location "%{wks.location}/Engine/Intermediate/ProjectFiles"
	kind "SharedLib"
	language "C++"

	targetdir ("%{wks.location}/Engine/Binaries/%{cfg.platform}")
	objdir ("%{wks.location}/Engine/Intermediate/Build/%{cfg.platform}/%{prj.name}")

	files
	{
		"%{wks.location}/Engine/**"
	}

	excludes
	{
		"%{wks.location}/Engine/Source/Programs/**",
		"%{wks.location}/Engine/Binaries/**",
		"%{wks.location}/Engine/Intermediate/**",
		"%{wks.location}/Engine/Extras/**"
	}

	includedirs
	{
		"%{wks.location}/Engine/Source/ThirdParty/spdlog/include",
		"%{wks.location}/Engine/Source/Fable"
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
