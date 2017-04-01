#if !defined(__Device_h_include__)
#define __Device_h_include__

#include "glm/glm.hpp"

namespace redcort
{
	namespace video
	{
		class Device
		{
		private:
			Device();
			Device(const Device& );

		public:
			~Device();

		private:
			glm::uvec2 m_screenSize;

		};
	}
}

#endif // !defined(__Device_h_include__)