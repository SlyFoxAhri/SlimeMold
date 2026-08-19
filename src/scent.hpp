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
        void addtoScentValue(int sv);
        int scentValue;
        Color scentColor;
        bool isCellHere;
        int changeValue;
    private:
};