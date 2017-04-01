#include "EngineStdAfx.h"
#include "FrameTimer.h"

namespace redcort
{
	namespace common
	{
		using namespace std::chrono_literals;

		FrameTimer::FrameTimer()
			: m_lastTime(0ns)
			, m_frameTime(0ns)
		{}

		FrameTimer::~FrameTimer()
		{}

		FrameTimer::frameTime_t FrameTimer::Count()
		{
			using namespace std::chrono;

			frameTime_t now =  high_resolution_clock::now().time_since_epoch();
			m_frameTime = now - m_lastTime;

			InitialCount();

			return m_frameTime;
		}
	}
}