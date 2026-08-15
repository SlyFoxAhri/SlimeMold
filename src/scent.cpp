#include "scent.hpp"

Scent::Scent()
{
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            Color clr = {0,0,(unsigned char)GetRandomValue(0,255),255};
            scentColorarray[i][j] = clr;
        }
    }
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

Scent::~Scent()
{

}