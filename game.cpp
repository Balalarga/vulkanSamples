#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game* Game::selfInstance = nullptr;

Game::Game()
{
}

Game &Game::Instance()
{
    if(!selfInstance)
        selfInstance = new Game();
    return *selfInstance;
}

bool Game::Init()
{
    WindowInfo windowInfo;
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        std::cout<<"SDL couldn't be inited\n";
        return false;
    }
    if(VulkanCore::Instance().Init(windowInfo.title)){
        std::cout<<"Vulkan couldn't be inited\n";
        return false;
    }
    std::cout<<"Available extentions:\n";
    for(auto& i: VulkanCore::Instance().getExtentions()){
        std::cout<<i.extensionName<<" - "<<i.specVersion<<std::endl;
    }
    mainWindow.reset(new VulkanWindow());

    if(!mainWindow->createWindow(windowInfo)){
        std::cout<<"Window not created\n";
        return false;
    }
    return true;
}

void Game::Render()
{

}

void Game::Update()
{
    if(!mainWindow->isOpen())
        isRunning = false;
}

void Game::HandleInput()
{

}

void Game::Clean()
{
    VulkanCore::Instance().CleanUp();
    mainWindow->destroyWindow();
    mainWindow = 0;
    SDL_Quit();
    delete selfInstance;
}

bool Game::Running()
{
    return false;
    return isRunning;
}
