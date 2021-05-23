project "Glad"
	location (ProjectsLocation)
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir (TargetDir)
	objdir (ObjDir)

	files
	{
		ProgramsSourceDir .. "Glad/include/Glad/Glad.h",
		ProgramsSourceDir .. "Glad/include/KHR/khrplatform.h",
		ProgramsSourceDir .. "Glad/src/Glad.c"
	}

	includedirs
	{
		"%{IncludeDir.Glad}"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
