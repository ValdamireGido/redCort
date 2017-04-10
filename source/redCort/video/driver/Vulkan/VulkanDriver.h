#pragma once 

#include "video/driver/Driver.h"

#include "vulkan/vulkan.h"

namespace redcort 
{
	namespace video
	{
		class VulkanExtensions;
		class VulkanPhysicalDevice;
		class VulkanDevice;

		class VulkanDriver
			: public Driver
		{
		public:
			VulkanDriver() = default;
			~VulkanDriver() = default;

			// this should be moved to driver base class then 
			void Init();
			void Deinit();
			
			VkInstance& GetVkInstance();

		private:
			void InitExtensions();

		private:
			VkInstance				m_pVkInstance;
			VulkanExtensions*		m_extensions;
			VulkanPhysicalDevice*	m_pPhysicalDevice;
			VulkanDevice*			m_pDevice;

			bool					m_isInitialized;
		};

		inline VkInstance& VulkanDriver::GetVkInstance()
		{
			return m_pVkInstance;
		}
	}
}
