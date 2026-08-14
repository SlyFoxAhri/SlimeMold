#pragma once
#include <raylib.h>
#include <raymath.h>

class Cell
{
    public:
        Cell();
        ~Cell();
        void Draw();
        void Update();
        float randomPosX;
        float randomPosY;
        float randomRotateAngle;
        int speed;
        Color color;
        Vector2 position;
        Vector2 direction;
        Rectangle rec;
        

    private:

};