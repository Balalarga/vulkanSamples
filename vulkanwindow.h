#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <string>

struct WindowInfo{
    std::string title = "Window";
    int width = 1020;
    int height = 720;
    int posX = SDL_WINDOWPOS_CENTERED;
    int posY = SDL_WINDOWPOS_CENTERED;
    unsigned int flags = SDL_WINDOW_SHOWN;
};

class VulkanWindow
{
public:
    VulkanWindow();
    std::string getName();
    bool createWindow(WindowInfo info);
    bool isOpen();
    void destroyWindow();
    SDL_Window* getSDLWindow();

private:
    SDL_Window* sdlWindow;
    WindowInfo windowInfo;
    bool isOpened = false;
};

#endif // WINDOW_H
