#pragma once
#include <raylib.h>
#include <raymath.h>
#include "cellule.hpp"
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
        void Smell(Vector2* L, Vector2* R, Vector2* C, Vector2* dir);
        void FollowSmell();
        int cellulNum;
        int changeAmount;
        float turnAngle;
        Cellule cellularray[1000];
        Scent scentarray[200][200];
    private:


    
};