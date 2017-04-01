#if !defined(__Version_h_include__)
#define __Version_h_include__

#include <string>

namespace redcort
{
	namespace info
	{
		std::string GetEngineName();
		uint32_t GetEngineVersion();

		std::string GetApplicationName();
		uint32_t GetApplicationVersion();
	}
}

#endif // __Version_h_include__
