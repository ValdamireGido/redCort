#include "EngineStdAfx.h"
#include "FPSCounter.h"

namespace redcort
{
	namespace video
	{
		FPSCounter::FPSCounter()
			: m_frameTimer()
		{}

		FPSCounter::~FPSCounter()
		{}

		FPSCounter::frameTime_t FPSCounter::Count()
		{
			frameTime_t frameTime = m_frameTimer.Count();
			m_fps = uint32_t((frameTime / 1000000000).count());
			return frameTime;
		}
	}
}