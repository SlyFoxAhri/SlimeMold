#pragma once
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "global.hpp" 

class Cell
{
    public:
        Cell();
        ~Cell();
        void Draw();
        void Update();
        float GetScent(float angle);
        float randomPosX;
        float randomPosY;
        float randomRotateAngle;
        int speed;
        float senseAngle;
        float senseLength;
        float turnAngle;
        float leftSmeller;
        float rightSmeller;
        float centerSmeller;
        Color color;
        Vector2 position;
        Vector2 direction;
        Rectangle rec;
        

    private:

};