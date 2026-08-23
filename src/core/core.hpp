#pragma once
#include <raylib.h>
#include <raymath.h>
#include "../objects/cellule.hpp"
#include "../objects/scent.hpp"
#include "../global.hpp"

 class Core
 {
    public:
        Core();
        ~Core();
        void Draw();
        void Update();
    private:
        int cellulNum;
        int scentLeftbyCellule;
        int temparray[180][180];
        Scent scentarray[180][180];
        Cellule cellularray[10000];
        void Smell(Cellule* currentcell);
        void LeaveScentTrail(int iterator);
        void DiffuseScent();
        int AvgScent(int x, int y);
 };