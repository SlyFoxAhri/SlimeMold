#pragma once
#include <raylib.h>
#include <raymath.h>
#include "cell.hpp"
#include "scent.hpp"
#include "global.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        int cellNum;
        Cell cellarray[1000];
        Scent scent;
    private:


    
};