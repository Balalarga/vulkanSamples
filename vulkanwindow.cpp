#include "vulkanwindow.h"

VulkanWindow::VulkanWindow()
{

}

std::string VulkanWindow::getName()
{
    return windowInfo.title.empty() ? "Window" : windowInfo.title;
}

bool VulkanWindow::createWindow(WindowInfo info)
{
    windowInfo = info;
    sdlWindow = SDL_CreateWindow(info.title.c_str(),
                                 info.posX,
                                 info.posY,
                                 info.width,
                                 info.height,
                                 SDL_WINDOW_VULKAN | info.flags);
    isOpened = true;
    if(sdlWindow)
        return true;
    return false;
}

bool VulkanWindow::isOpen()
{
    return false;
}

void VulkanWindow::destroyWindow()
{
    SDL_DestroyWindow(sdlWindow);
}

SDL_Window *VulkanWindow::getSDLWindow()
{
    return sdlWindow;
}
