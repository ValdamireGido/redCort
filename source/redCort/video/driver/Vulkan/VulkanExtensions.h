#pragma once

#include "VulkanDriver.h"

namespace redcort
{
	namespace video
	{
		class VulkanExtensions
		{
		public:
			VulkanExtensions();

			void PushExtension(const char* ext);
			void PushExtensions(const std::vector<const char*>& exts);

			const char* const* raw() const;
			uint32_t count() const;

		private:
			std::vector<const char*> m_extensions;
		};


		inline const char* const* VulkanExtensions::raw() const
		{
			return &m_extensions[0];
		}


		inline uint32_t VulkanExtensions::count() const
		{
			return static_cast<uint32_t>(m_extensions.size());
		}
	}
}