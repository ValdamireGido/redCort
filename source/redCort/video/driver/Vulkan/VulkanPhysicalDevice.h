#pragma once 

#include "vulkan/vulkan.h"

namespace redcort 
{
	namespace video 
	{
		class VulkanPhysicalDevice
		{
		public:
			static constexpr int k_maxPhysicalDevices = 15;

		public:
			VulkanPhysicalDevice() = default;
			~VulkanPhysicalDevice() = default;

			void Init(VkInstance pVkInstance);
			void Deinit();

			VkPhysicalDevice	GetPhysicalDevice(size_t idx);
			uint32_t			GetPhysicalDevicesCount(size_t idx);

			bool				IsInitialized() const;

		private:
			VkPhysicalDevice	m_pPhysicalDevices[k_maxPhysicalDevices];
			uint32_t			m_pPhysicalDevicesCount[k_maxPhysicalDevices];

			bool				m_isInitialized;
		};

		/* 
			Inline Relization 
		*/

		inline VkPhysicalDevice VulkanPhysicalDevice::GetPhysicalDevice(size_t idx)
		{
			RASSERT(idx < k_maxPhysicalDevices);
			return m_pPhysicalDevices[idx];
		}

		inline uint32_t VulkanPhysicalDevice::GetPhysicalDevicesCount(size_t idx)
		{
			RASSERT(idx < k_maxPhysicalDevices);
			return m_pPhysicalDevicesCount[idx];
		}

		inline bool VulkanPhysicalDevice::IsInitialized() const
		{
			return m_isInitialized;
		}
	}
}