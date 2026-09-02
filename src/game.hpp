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