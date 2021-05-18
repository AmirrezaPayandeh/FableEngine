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


group "Programs"
    include "Engine/Programs/GLFW"
    include "Engine/Programs/Sandbox"
group ""

group "Engine"
    include "Engine/Programs/FE"
group ""
