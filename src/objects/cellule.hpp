#pragma once
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "../global.hpp" 

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
        Vector2 position;
        Vector2 direction;
        Color color;
        int speed;
        float senseAngle;
        float senseLength;
        Vector2 leftSmeller;
        Vector2 rightSmeller;
        Vector2 centerSmeller;
    private:

};