#include "scent.hpp"
#include <raylib.h>

Scent::Scent()
{
    cellcount = 200;
    scentColorarray[200][200];
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            Color clr = {0,0,GetRandomValue(0,255),255};
            scentColorarray[i][j] = clr;
        }
    }
}

Scent::~Scent()
{

}

void Scent::Draw()
{
    for (int i = 0; i < cellcount*4; i = i + 4)
    {
        for (int j = 0; j < cellcount*4; j = j + 4)
        {
            Color clr = scentColorarray[i/4][j/4];
            DrawRectangle(i, j, 4, 4, clr);
        }
    }
}

void Scent::Update()
{
    //use the color already set at object creation
    //scentColor = from original color
    //some function that gets it???
}

Color Scent::GetColor()
{
    //iterate 200x200 array
    //store color???
}