workspace "FableEngine"
	architecture "x64"
	platforms { "Win64" }
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

Platform = "%{cfg.platform}"
ProjectName = "%{prj.name}"

SolutionDir = "%{wks.location}/"
EngineDir = SolutionDir .. "Engine/"
SourceDir = EngineDir .. "Source/"
ProgramsSourceDir = SourceDir .. "Programs/"
ThirdPartySourceDir = SourceDir .. "ThirdParty/"

ProjectsLocation = EngineDir .. "Intermediate/ProjectFiles"

BinariesDir = EngineDir .. "Binaries/"
IntermediateDir = EngineDir .. "Intermediate/"
ExtrasDir = EngineDir .. "/Extras/"

TargetDir = BinariesDir .. Platform
ObjDir = IntermediateDir .. "Build/" .. Platform .. "/" .. ProjectName

---------------------------- [[ Include Directories ]] ----------------------------
IncludeDir = {}

-- Third Parties
IncludeDir["spdlog"] = ThirdPartySourceDir .. "spdlog/include/"
IncludeDir["GLFW"] = ProgramsSourceDir .. "GLFW/include/"
IncludeDir["Glad"] = ProgramsSourceDir .. "Glad/include/"

-- Engine
IncludeDir["Fable"] = SourceDir .. "Fable/"
IncludeDir["FableCore"] = SourceDir .. "Fable/Core/"
IncludeDir["FableApplicationCore"] = SourceDir .. "Fable/ApplicationCore/"


group "Programs"
	include "Engine/Programs/GLFW/"
	include "Engine/Programs/Glad/"
    include "Engine/Programs/Sandbox/"
group ""

group "Engine"
    include "Engine/Programs/FE/"
group ""
