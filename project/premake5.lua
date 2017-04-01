solution "redCort"
	location(_ACTION)
	configurations
	{
		"Debug",
		"Release"
	}
	
	defines 
	{
		"_SCL_SECURE_NO_WARNINGS", 
		"_CRT_SECURE_NO_WARNINGS"
	}

	defines { "_SCL_SECURE_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS" }	
	startproject "Test"
	
dofile("projectPremake5.lua")

project "Test"
	targetname "Test"
	kind "ConsoleApp"
	language "C++"
	location("Test/" .. _ACTION)
	
	includedirs { 
		"Test/src",
		"../source",
		"../../vulkan/1.0.17.0/Include/",
	}
	
	links {
		"vulkan-1", 
		"VKstatic.1",
		"VkLayer_utils",
		"VkLayer_unique_objects",
		"redCort"		
	}
	
	files {
		"Test/src/**",
	}
	
	libdirs {
		"../../vulkan/1.0.17.0/lib32",
		"../product/debug"
	}
	
	configuration "Debug"
		targetdir("Test/debug")
		defines { "G_DEBUG" }
		debugdir "Test/debug"
		flags { "Symbols" }
		
	configuration "Release"
		targetdir("Test/release")
		debugdir "Test/release"
		flags { "Optimize" }
		