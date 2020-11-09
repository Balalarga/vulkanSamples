#include "game.h"
#include <iostream>

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
    videoSystem = std::make_unique<VideoSystem>();
    WindowInfo windowInfo;
    videoSystem->Init("Application");
}

void Game::Render()
{

}

void Game::Update()
{
    if(!videoSystem->GetWindow().isOpen())
        isRunning = false;
}

void Game::HandleInput()
{

}

void Game::Clean()
{
    videoSystem->CleanUp();

    delete selfInstance;
}

bool Game::Running()
{
    return false;
    return isRunning;
}
