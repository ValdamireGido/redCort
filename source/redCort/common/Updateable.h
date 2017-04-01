#if !defined(__Updateable_h_include__)
#define __Updateable_h_include__

#include "Result.h"

#include <chrono>
#include <thread>

namespace redcort
{
	class Updateable
	{
	public:
		static void Update(Updateable* _updateable);
		static std::chrono::nanoseconds GetTimeDiffSinceLast();

	public:
		Updateable() = default;
		virtual ~Updateable() = default;

		virtual void Update(std::chrono::nanoseconds frameTime) = 0;
		virtual bool ShouldWork() const = 0;
	};
}
#endif // __Updateable_h_include__