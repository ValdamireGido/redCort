#pragma once

#include "video/driver/Device.h"
#include "vulkan/vulkan.h"

namespace redcort 
{
	namespace video
	{
		class VulkanPhysicalDevice;

		class VulkanDevice
		{
		public:
			VulkanDevice() = default;
			~VulkanDevice() = default;

			void Init(VkInstance pVkInstance, VulkanPhysicalDevice* pVulkanPhysicalDevice);
			void Deinit();

			VkDevice GetDevice();

			bool IsInitialized() const;

		private:
			VkDevice					m_pVkDevice;
			VkDeviceQueueCreateInfo		m_vkQueueCreateInfo;
			VkDeviceCreateInfo			m_vkCreateInfo;

			bool						m_isInitialized;
		};

		/*
			Inline realization
		*/

		inline VkDevice VulkanDevice::GetDevice()
		{
			return m_pVkDevice;
		}

		inline bool VulkanDevice::IsInitialized() const 
		{
			return m_isInitialized;
		}
	}
}