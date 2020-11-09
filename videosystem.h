#ifndef VIDEOSYSTEM_H
#define VIDEOSYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <vulkan/vulkan.h>
#include <vulkan/vk_sdk_platform.h>
#include <SDL2/SDL.h>

#include "vulkanwindow.h"

class VideoSystem
{
public:
    VideoSystem();
    bool Init(std::string appName);
    void CleanUp();
    void InitExtensions(VulkanWindow* vulkanWindow);
    std::vector<const char*> GetExtensions();
    VulkanWindow& GetWindow();

private:
    VkInstance vulkanInstance;
    std::vector<const char*>  vulkanExtensions{};
    std::vector<const char*>  vulkanLayers{};
    std::unique_ptr<VulkanWindow> vulkanWindow;

    bool InitVulkan();
    bool InitSDL();
    void CleanSDL();
    void CleanVulkan();
};

#endif // VIDEOSYSTEM_H
