#include "scent.hpp"

Scent::Scent()
{
    scentValue = GetRandomValue(0, 255);
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    isCellHere = false;
    changeValue = 2;
}

void Scent::Draw(int x, int y)
{
    //decrese scent constatntly all over
    //BUT when function is called increase it??
    scentValue -= changeValue;
    if(scentValue <= 0)
    {scentValue = 0;}
    
    //scentColor = ChangeScentColor();
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    DrawRectangle(x, y, 4, 4, scentColor);
}

Color Scent::ChangeScentColor()
{
    Color newscentcolor;
    int value = 10;

    scentValue += value*3;
    scentColor = {0, 0, (unsigned char)scentValue, 255};

    return newscentcolor;
}

Scent::~Scent()
{

}