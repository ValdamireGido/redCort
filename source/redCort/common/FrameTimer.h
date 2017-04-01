#if !defined(__Frame_Timer_h_include__)
#define __Frame_Timer_h_include__

#include <chrono>

namespace redcort
{
	namespace common
	{
		class FrameTimer
		{
		public:
			using frameTime_t = std::chrono::nanoseconds;

		public:
			FrameTimer();
			~FrameTimer();

			void InitialCount();
			frameTime_t Count();
			frameTime_t GetFrameTime() const;

		private:
			frameTime_t m_frameTime;
			frameTime_t m_lastTime;
		};

		/** 
			Inline methods realization
		*/ 

		inline void FrameTimer::InitialCount()
		{
			using namespace std::chrono;

			m_lastTime = high_resolution_clock::now().time_since_epoch();
		}

		inline FrameTimer::frameTime_t FrameTimer::GetFrameTime() const 
		{
			return m_frameTime;
		}
	}
}

#endif // __Frame_Timer_h_include__