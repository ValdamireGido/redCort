#include "EngineStdAfx.h"
#include "VulkanDriver.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDevice.h"

namespace redcort
{
	namespace video
	{
		void VulkanDriver::Init()
		{
			if (m_isInitialized)
			{
				RASSERT2(!m_isInitialized, "Vulkan Driver is already initialzied.");
				return;
			}

			VkApplicationInfo vkApplicationInfo;
			vkApplicationInfo.sType				 = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			vkApplicationInfo.pNext				 = nullptr;
			vkApplicationInfo.pApplicationName	 = redcort::info::GetApplicationName().c_str();
			vkApplicationInfo.applicationVersion = redcort::info::GetApplicationVersion();
			vkApplicationInfo.pEngineName		 = redcort::info::GetEngineName().c_str();
			vkApplicationInfo.engineVersion		 = redcort::info::GetEngineVersion();
			vkApplicationInfo.apiVersion		 = VK_API_VERSION_1_0;

			VkInstanceCreateInfo vkInstanceCreateInfo;
			vkInstanceCreateInfo.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			vkInstanceCreateInfo.pNext						= nullptr;
			vkInstanceCreateInfo.flags						= 0u;
			vkInstanceCreateInfo.pApplicationInfo			= &vkApplicationInfo;
			vkInstanceCreateInfo.enabledLayerCount			= 1u;
			vkInstanceCreateInfo.ppEnabledExtensionNames	= nullptr;		// TODO: Need to move to specific controller
			vkInstanceCreateInfo.enabledExtensionCount		= 0u;			// 
			vkInstanceCreateInfo.ppEnabledLayerNames		= nullptr;		// TODO: Need to move to specific controller
			vkInstanceCreateInfo.enabledLayerCount			= 0u;			//

			VkResult result = vkCreateInstance(&vkInstanceCreateInfo, 
											   nullptr, 
											   &m_pVkInstance);
			RASSERT(result == VkResult::VK_SUCCESS);
			if (result != VkResult::VK_SUCCESS)
			{
				return;
			}

			m_pPhysicalDevice = new VulkanPhysicalDevice();
			RASSERT(m_pPhysicalDevice);
			if (!m_pPhysicalDevice)
			{
				return;
			}

			m_pPhysicalDevice->Init(m_pVkInstance);
			RASSERT(m_pPhysicalDevice->IsInitialized());
			if (!m_pPhysicalDevice->IsInitialized())
			{
				delete m_pPhysicalDevice;
				m_pPhysicalDevice = nullptr;

				return;
			}

			m_pDevice = new VulkanDevice();
			RASSERT(m_pDevice);
			if (!m_pDevice)
			{
				return;
			}

			m_pDevice->Init(m_pVkInstance, m_pPhysicalDevice);
			RASSERT(m_pDevice->IsInitialized());
			if (!m_pDevice->IsInitialized())
			{
				delete m_pDevice;
				m_pDevice = nullptr;

				return;
			}

			m_isInitialized = true;
		}

		void VulkanDriver::Deinit()
		{
			if (!m_isInitialized)
			{
				RASSERT2(m_isInitialized, "Vulkan Driver is not initialized to be destroyed.");
				return;
			}

			if (m_pDevice)
			{
				delete m_pDevice;
				m_pDevice = nullptr;
			}

			if (m_pPhysicalDevice)
			{
				delete m_pPhysicalDevice;
				m_pPhysicalDevice = nullptr;
			}
		}
	}
}