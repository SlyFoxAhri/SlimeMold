#pragma once
#include <raylib.h>
#include <raymath.h>
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
        bool isPaused;
        bool isPanelShown;
        bool isMousePressed;
    private:
        Core gameCore; 
        Panel panel;
};