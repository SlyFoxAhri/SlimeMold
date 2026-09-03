#pragma once
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "global.hpp" 

class Cellule
{
    public:
        Cellule();
        Cellule(int startPosition, int edgeBehaviour);
        ~Cellule();
        Vector2 position;
        Vector2 direction;
        float senseAngle;
        float turnAngle;
        float senseLength;
        Vector2 leftSmeller;
        Vector2 rightSmeller;
        Vector2 centerSmeller;
        void Draw();
        void Update();
        void Sense();
        void Smell();
        void SetDirection(Vector2 newPos);
    private:
        Color color;
        int speed;
        Vector2 SensePositon(float angle);
        bool isEdgy;
};