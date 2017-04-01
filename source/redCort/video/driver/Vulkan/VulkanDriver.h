#pragma once 

#include "video/driver/Driver.h"

#include "vulkan/vulkan.h"

namespace redcort 
{
	namespace video
	{
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
			VkInstance				m_pVkInstance;
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
