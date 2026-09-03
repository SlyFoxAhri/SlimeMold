#pragma once
#include <raylib.h>
#include <raymath.h>
#include <memory>
#include "cellule.hpp"
#include "scent.hpp"
#include "core.hpp"
#include "panel.hpp"
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
};