#include "EngineStdAfx.h"
#include "VulkanExtensions.h"

namespace redcort
{
	namespace video
	{
		VulkanExtensions::VulkanExtensions()
			: m_extensions()
		{}

		void VulkanExtensions::PushExtension(const char* ext)
		{
			m_extensions.push_back(ext);
		}

		void VulkanExtensions::PushExtensions(const std::vector<const char*>& exts)
		{
			std::for_each(exts.begin(), exts.end(), 
						  std::bind(&VulkanExtensions::PushExtension, this, std::placeholders::_1));
		}
	}
}