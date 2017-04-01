#include "EngineStdAfx.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"

namespace redcort 
{
	namespace video
	{
		void VulkanDevice::Init(VkInstance pVkInstance, VulkanPhysicalDevice* pVulkanPhysicalDevice)
		{
			if (!pVulkanPhysicalDevice->IsInitialized())
			{
				return;
			}

			m_vkQueueCreateInfo.sType				= VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			m_vkQueueCreateInfo.pNext				= nullptr;
			m_vkQueueCreateInfo.flags				= 0u;
			const float queuePriorities[] = { 1.f, 0.1f };
			m_vkQueueCreateInfo.pQueuePriorities	= queuePriorities;
			m_vkQueueCreateInfo.queueCount			= 1u;

			m_vkCreateInfo.sType				= VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
			m_vkCreateInfo.pNext				= nullptr;
			m_vkCreateInfo.flags				= 0u;
			m_vkCreateInfo.pQueueCreateInfos	= &m_vkQueueCreateInfo;
			m_vkCreateInfo.queueCreateInfoCount = 1u;
			m_vkCreateInfo.enabledLayerCount	= 0u;
			m_vkCreateInfo.enabledExtensionCount = 0u;
			m_vkCreateInfo.pEnabledFeatures		= nullptr;

			VkResult result = vkCreateDevice(pVulkanPhysicalDevice->GetPhysicalDevice(0ul), 
											 &m_vkCreateInfo, 
											 nullptr, 
											 &m_pVkDevice);
			RASSERT(result == VkResult::VK_SUCCESS);
			if (result != VkResult::VK_SUCCESS)
			{
				return;
			}

			m_isInitialized = true;
		}

		void VulkanDevice::Deinit()
		{
			m_isInitialized = false;
		}
	}
}