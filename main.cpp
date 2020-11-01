#include <iostream>
#include "game.h"
using namespace std;



#include <SDL2/SDL.h>

void mainLoop(){
    while(Game::Instance().Running()){
        Game::Instance().HandleInput();
        Game::Instance().Update();
        Game::Instance().Render();
    }
}

int main(int argc, char** argv)
{

    cout<<"Application start\n";
    if(!Game::Instance().Init()){
        cout<<"Initialize error\n";
        return -1;
    }
    mainLoop();
    Game::Instance().Clean();
    cout<<"Application end\n";
    return 0;
}
