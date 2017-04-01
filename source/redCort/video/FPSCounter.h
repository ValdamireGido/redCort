#if !defined(__FPS_Counter_h_include__)
#define __FPS_Counter_h_include__

#include "common/FrameTimer.h"

#include <chrono>

namespace redcort
{
	namespace video
	{
		class FPSCounter
		{
		public:
			using frameTime_t = common::FrameTimer::frameTime_t;

		public:
			FPSCounter();
			~FPSCounter();

			/** void Start() 
				- should be called before the update loop start
			*/
			void Start();

			/** void Count() 
				- method to count the fps for every loop cycle. 
				should be called every loop cycle. 
			*/ 
			frameTime_t Count();

			/** time_t GetFrameTime() const 
				- returns the time spent for one frame. 
				should be called after the void Count() method. 
			*/
			frameTime_t GetFrameTime() const;

		private:
			common::FrameTimer m_frameTimer;
			uint32_t m_fps;
		};

		/**
			Inline methods realization
		**/
		
		inline 
			void 
			FPSCounter::Start()
		{
			m_frameTimer.InitialCount();
		}

		inline 
			FPSCounter::frameTime_t 
			FPSCounter::GetFrameTime() const
		{
			return m_frameTimer.GetFrameTime();
		}
	}
}

#endif // !defined(__FPS_Counter_h_include__)