#ifndef VULKANCORE_H
#define VULKANCORE_H

#include <iostream>
#include <string>
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vk_sdk_platform.h>


class VulkanCore
{
public:
    static VulkanCore& Instance();

    bool Init(std::string appName);
    void CleanUp();
    std::vector<VkExtensionProperties> getExtentions();

private:
    VulkanCore();
    static VulkanCore* selfInstance;

    VkInstance vulkanInstance;
};

#endif // VULKANCORE_H
