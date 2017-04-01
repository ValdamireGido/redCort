#include "EngineStdAfx.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDriver.h"


namespace redcort
{
	namespace video
	{
		void VulkanPhysicalDevice::Init(VkInstance pVkInstance)
		{
			VkResult result = vkEnumeratePhysicalDevices(pVkInstance, 
														 m_pPhysicalDevicesCount, 
														 m_pPhysicalDevices);
			RASSERT(result == VkResult::VK_SUCCESS);
			if (result != VkResult::VK_SUCCESS)
			{
				return;
			}

			m_isInitialized = true;
		}

		void VulkanPhysicalDevice::Deinit()
		{
			m_isInitialized = false;
		}
		
	}
}