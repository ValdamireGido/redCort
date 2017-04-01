#include "EngineStdAfx.h"
#include "Version.h"

namespace redcort
{
	namespace info
	{
		const std::string g_engineName("redCort");
		const uint32_t g_engineVersion(1000u);
		
		const std::string g_applicationName("Game_redCort");
		const uint32_t g_applicationVersion(101000u);

		// ----------------------------------------------------

		std::string GetEngineName()
		{
			return g_engineName;
		}

		uint32_t GetEngineVersion()
		{
			return g_engineVersion;
		}

		std::string GetApplicationName()
		{
			return g_applicationName;
		}

		uint32_t GetApplicationVersion()
		{
			return g_applicationVersion;
		}
	}

}
