#pragma once

#include "Updateable.h"

class std::thread;

namespace redcort
{
	class AsyncUpdateable
		: protected Updateable
	{
	public:
		AsyncUpdateable() = default;
		virtual ~AsyncUpdateable();

		static void AsyncUpdate(AsyncUpdateable* _updateable);

	private:

		std::thread* m_thread;
	};
}