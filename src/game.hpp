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
        void CreateSmell(int iterator);
        int cellulNum;
        float turnAngle;
        int maxSmell;
        int diffusedsmell;
        Cellule cellularray[10000];
        Scent scentarray[200][200];
    private:


    
};