#pragma once
#include <raylib.h>
#include <raymath.h>
#include "objects/cellule.hpp"
#include "objects/scent.hpp"
#include "global.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        void Diffuse();
        int Avg(int x, int y);
        void Smell(Vector2* L, Vector2* R, Vector2* C, Vector2* dir);
        void CreateSmell(int iterator);
        int cellulNum;
        float turnAngle;
        int maxSmell;
        int diffusedsmell;
        Cellule cellularray[10000];
        //if increased by 1 from 180 anomaly dissapears
        Scent scentarray[180][180];
    private:


    
};