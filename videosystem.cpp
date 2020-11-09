#include "videosystem.h"
using namespace std;

bool VideoSystem::Init(std::string appName)
{
    if(!InitSDL()){
        return false;
    }
    vulkanWindow = make_unique<VulkanWindow>();
    WindowInfo info;
    info.title = appName;
    if(vulkanWindow->createWindow(info)){
        return false;
    }
    if(InitVulkan()){
        return false;
    }
    return true;
}

void VideoSystem::CleanUp()
{
    vulkanWindow->destroyWindow();
    vulkanWindow = 0;
    CleanVulkan();
    CleanSDL();
}

std::vector<const char*> VideoSystem::GetExtensions()
{
    return vulkanExtensions;
}

VulkanWindow& VideoSystem::GetWindow()
{
    return *vulkanWindow;
}

VideoSystem::VideoSystem()
{
}

void VideoSystem::InitExtensions(VulkanWindow* vulkanWindow)
{
    uint32_t extensionCount = 0;

    // Последний параметр говорит, что нужно получить кол-во
    SDL_Vulkan_GetInstanceExtensions(vulkanWindow->getSDLWindow(), &extensionCount, nullptr);

    // Получение списка данных
    SDL_Vulkan_GetInstanceExtensions(vulkanWindow->getSDLWindow(), &extensionCount, vulkanExtensions.data());

}

bool VideoSystem::InitVulkan()
{
    // Струкрута для создания инстанции Vulkan'a
    VkApplicationInfo appInfo = {};

    // Определение типа структуры
    // требуется для всех Vk-структур
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

    //Имя приложение
    appInfo.pApplicationName = vulkanWindow->getName().c_str();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "None";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 1, 1);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //...
    vector<const char*> layers{};

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = layers.size();
    createInfo.ppEnabledLayerNames = layers.data();
    createInfo.enabledExtensionCount = vulkanExtensions.size();
    createInfo.ppEnabledExtensionNames = vulkanExtensions.data();


    // Создание инстанции
    VkResult result = vkCreateInstance(&createInfo, nullptr, &vulkanInstance);
    if(result != 0){
        std::cout<<"Vulkan initialization error\n";
        return false;
    }
    return true;
}

bool VideoSystem::InitSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS))
        return false;
    return true;

}

void VideoSystem::CleanSDL()
{
    SDL_Quit();
}

void VideoSystem::CleanVulkan()
{
    // Очистка данных Vulkan
    // Второй параметр - allocator callback
    vkDestroyInstance(vulkanInstance, nullptr);
}
