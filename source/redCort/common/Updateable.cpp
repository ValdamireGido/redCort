#include "EngineStdAfx.h"
#include "Updateable.h"

namespace redcort 
{
	void Updateable::Update(Updateable* _updateable)
	{
		DASSERT(_updateable);
		while(_updateable->ShouldWork())
		{
			_updateable->Update(GetTimeDiffSinceLast());
		}
	}

	std::chrono::nanoseconds Updateable::GetTimeDiffSinceLast()
	{
		using namespace std;
		using namespace chrono;

		static system_clock::time_point lastTp = system_clock::now();
		system_clock::time_point diff = system_clock::now() - lastTp.time_since_epoch();
		lastTp = system_clock::now();
		return diff.time_since_epoch();
	}
}