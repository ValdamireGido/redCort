project "redCort"
	targetname "redCort"
	kind "StaticLib"
	
	location(_ACTION)
	debugdir(_ACTION .. "build")
	files 
	{
		"../source/**"
	}
	
	pchheader "EngineStdAfx.h"
	pchsource "../source/redCort/EngineStdAfx.cpp"
	
	includedirs { 
		"../source/redcort",
		"../source/redcort/video",
		"../../glm",
		"../../vulkan/1.0.17.0/Include",
	}
	
	libdirs { 
		"../../vulkan/1.0.17.0/lib32"
	}
	
	configuration "Debug"
		targetdir("../product/debug")
		defines { "G_DEBUG" }
		flags { "Symbols" }
		
	configuration "Release"
		targetdir("../product/release")
		defines { "G_RELEASE" }
		flags { "Optimize" }
		