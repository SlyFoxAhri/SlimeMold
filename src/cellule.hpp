#pragma once
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "global.hpp" 

class Cellule
{
    public:
        Cellule();
        ~Cellule();
        void Draw();
        void Update();
        void Sense();
        Vector2 SensePositon(float angle);
        float randomPosX;
        float randomPosY;
        float randomRotateAngle;
        int speed;
        float senseAngle;
        float senseLength;
        float turnAngle;
        Vector2 leftSmeller;
        Vector2 rightSmeller;
        Vector2 centerSmeller;
        Color color;
        Vector2 position;
        Vector2 direction;
        Rectangle rec;
    private:

};