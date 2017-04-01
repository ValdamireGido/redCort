#include "EngineStdAfx.h"
#include "AsyncUpdateable.h"

#include <thread>

namespace redcort
{
	AsyncUpdateable::~AsyncUpdateable()
	{
		if (m_thread)
		{
			m_thread->join();

			delete m_thread;
			m_thread = nullptr;
		}
	}

	void AsyncUpdateable::AsyncUpdate(AsyncUpdateable* _updateable)
	{
		ASSERT_PTR_VOID_RETURN(_updateable);
		RASSERT2(_updateable->m_thread == nullptr, "Async Updateable thread is already created. Ingoring call.");
		if (_updateable->m_thread)
		{
			return;
		}

		_updateable->m_thread = new std::thread([_updateable] ()
		{
			_updateable->Update(_updateable);
		});
	}
}