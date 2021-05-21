project "ImGui"
	location (ProjectsLocation)
	kind "StaticLib"
	language "C++"
    staticruntime "off"

	targetdir (TargetDir)
	objdir (ObjDir)

	files
	{
		ProgramsSourceDir .. "ImGui/*.h",
		ProgramsSourceDir .. "ImGui/*.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Distribution"
		runtime "Release"
		optimize "on"