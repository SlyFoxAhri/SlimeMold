#pragma once 
#include <raylib.h>
#include "global.hpp"

class Scent
{
    public:
        Scent();
        ~Scent();
        //Color scentColorarray[200][200];
        int scentValue;
        Color scentColor;
        bool isCellHere;
        int changeValue;
        void Draw(int x, int y);
        void Update();
        Color ChangeScentColor();

    private:
};