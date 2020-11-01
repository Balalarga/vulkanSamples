#include "vulkancore.h"
using namespace std;


VulkanCore* VulkanCore::selfInstance = nullptr;

VulkanCore &VulkanCore::Instance()
{
    if(!selfInstance)
        selfInstance = new VulkanCore;
    return *selfInstance;
}

bool VulkanCore::Init(std::string appName)
{
    // Струкрута для создания инстанции Vulkan'a
    VkApplicationInfo appInfo{};

    // Определение типа структуры
    // требуется для всех Vk-структур
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

    //Имя приложение
    appInfo.pApplicationName = appName.c_str();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "VoxelEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 1, 1);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //...
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = 0;

    // Создание инстанции
    VkResult result = vkCreateInstance(&createInfo, nullptr, &vulkanInstance);
    if(result != 0){
        std::cout<<"Vulkan initialization error\n";
        return false;
    }
    return true;
}

void VulkanCore::CleanUp()
{
    // Очистка данных Vulkan
    // Второй параметр - allocator callback
    vkDestroyInstance(vulkanInstance, nullptr);

    delete selfInstance;
}

std::vector<VkExtensionProperties> VulkanCore::getExtentions()
{
    uint32_t extensionCount = 0;

    // Последний параметр говорит, что нужно получить кол-во
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    vector<VkExtensionProperties> extensions(extensionCount);

    // Получение списка данных
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    return extensions;
}

VulkanCore::VulkanCore()
{
}
