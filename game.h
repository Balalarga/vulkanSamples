#ifndef GAME_H
#define GAME_H

#include "videosystem.h"
#include "vulkanwindow.h"
#include <memory>

class Game
{
public:
    static Game& Instance();
    bool Init();
    void Render();
    void Update();
    void HandleInput();
    void Clean();
    bool Running();

private:
    Game();
    static Game* selfInstance;
    bool isRunning = false;
    std::unique_ptr<VideoSystem> videoSystem;


};

#endif // GAME_H
