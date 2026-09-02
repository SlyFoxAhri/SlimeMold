#pragma once
#include <raylib.h>
#include <raymath.h>
#include <memory>
#include "objects/cellule.hpp"
#include "objects/scent.hpp"
#include "core/core.hpp"
#include "ui/panel.hpp"
#include "global.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
    private:
        //Core gameCore; 
        std::unique_ptr<Core> gameCore;
        
        Panel panel;
        Color scentcolor;
        Color agentcolor;
        int startPosition;
        int edgeBehaviour;
        bool isPaused;
        bool isPanelShown;
        bool isLeftMousePressed;
        bool isRightMousePressed;

        //enum startPos {SCATTER_START = 1, CENTER_START = 0};
        //enum edgeBvr {WRAP = 1, EDGE = 0};
};