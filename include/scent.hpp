#pragma once 
#include <raylib.h>
#include "global.hpp"

class Scent
{
    public:
        Scent();
        ~Scent();
        void Draw(int x, int y);
        void Update();
        int GetScentValue();
        void SetScentvalue(int newValue);
        void ChangeScentvalue(int changeValue);
    private:
        int scentValue;
        Color scentColor;
        int evaporationValue;
};