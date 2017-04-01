#include "redCort/RedCort.h"
#include "vulkan/vulkan.h"

#include <cstdlib>

#define MAX_PHYSICAL_DEVICES 16

#include "redCort/common/Updateable.h"

class Drawable
	: public redcort::Updateable
{
public:
	Drawable() {}
	~Drawable()	{}

protected:
	virtual void Update(std::chrono::nanoseconds frameTime) override
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		printf("\nframeTime = %ull", frameTime);
	}

	virtual bool ShouldWork() const override
	{
		return true;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	VkInstance pVkInstance; 

	VkApplicationInfo vkApplicationInfo;
	vkApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	vkApplicationInfo.pNext = nullptr;
	vkApplicationInfo.pApplicationName = redcort::info::GetApplicationName().c_str();
	vkApplicationInfo.applicationVersion = redcort::info::GetApplicationVersion();
	vkApplicationInfo.pEngineName = redcort::info::GetEngineName().c_str();
	vkApplicationInfo.engineVersion = redcort::info::GetEngineVersion();
	vkApplicationInfo.apiVersion = VK_API_VERSION_1_0;

	{
		VkInstanceCreateInfo vkInstanceCreateInfo;
		vkInstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		vkInstanceCreateInfo.pNext = nullptr;
		vkInstanceCreateInfo.flags = uint32_t(0);
		vkInstanceCreateInfo.pApplicationInfo = &vkApplicationInfo;
		vkInstanceCreateInfo.enabledLayerCount = uint32_t(1);
		vkInstanceCreateInfo.ppEnabledExtensionNames = nullptr;
		vkInstanceCreateInfo.enabledExtensionCount = 0u;
		vkInstanceCreateInfo.ppEnabledLayerNames = nullptr;
		vkInstanceCreateInfo.enabledLayerCount = 0u;

		VkResult result = vkCreateInstance(&vkInstanceCreateInfo,
										   nullptr, 
										   &pVkInstance);
		if(result != VkResult::VK_SUCCESS)
		{
			printf("Failed to create VkInstance (%d)", result);
			return EXIT_FAILURE;
		}
	}

	VkPhysicalDevice physicalDevice[MAX_PHYSICAL_DEVICES];
	uint32_t physicalDevicesCount[MAX_PHYSICAL_DEVICES];
	{
		VkResult result = vkEnumeratePhysicalDevices(pVkInstance,
													 physicalDevicesCount,
													 physicalDevice);
		if(result != VkResult::VK_SUCCESS)
		{
			printf("Failed to enumerate physical devices (%d)", result);
			return EXIT_FAILURE;
		}
	}

	VkDevice vkDevice;
	VkDeviceQueueCreateInfo deviceQueueCreateInfo;
	deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	deviceQueueCreateInfo.pNext = nullptr;
	deviceQueueCreateInfo.flags = uint32_t(0);

	const float queuePriorities[] = { 1.f, 0.1f };
	deviceQueueCreateInfo.pQueuePriorities = queuePriorities;
	deviceQueueCreateInfo.queueCount = uint32_t(1);
	
	VkDeviceCreateInfo createInfo;
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pNext = nullptr;
	createInfo.flags = 0;
	createInfo.pQueueCreateInfos = &deviceQueueCreateInfo;
	createInfo.queueCreateInfoCount = uint32_t(1);
	createInfo.enabledLayerCount = uint32_t(0);
	createInfo.enabledExtensionCount = uint32_t(0);
	createInfo.pEnabledFeatures = nullptr;

	{
		VkResult result = vkCreateDevice(physicalDevice[0],
										 &createInfo,
										 nullptr, 
										 &vkDevice);
		if(result != VkResult::VK_SUCCESS)
		{
			printf("Failed to create VkDevice (%d)", result);
			return EXIT_FAILURE;
		}
	}

	Drawable drawable;

	std::thread* drawableUpdateThread = new std::thread([&drawable] ()
	{
		redcort::Updateable::Update(&drawable);
	});

	drawableUpdateThread->join();
	
	return EXIT_SUCCESS;
}