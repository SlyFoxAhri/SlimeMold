#pragma once 
#include <raylib.h>
#include "global.hpp"

class Scent
{
    public:
        Scent();
        ~Scent();
        Color scentColorarray[200][200];
        void Draw();
        void Update();

    private:
};