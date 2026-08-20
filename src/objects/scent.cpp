#include "scent.hpp"

Scent::Scent()
{
    //scentValue = GetRandomValue(0, 255);
    scentValue = 0;
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    changeValue = 1;
}

void Scent::Draw(int x, int y)
{
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    DrawRectangle(x, y, 4, 4, scentColor);
}

void Scent::Update()
{
    scentValue -= changeValue;
    if(scentValue < 0)
    {scentValue = 0;}
}

void Scent::addtoScentValue(int sv)
{
    scentValue += sv;
    if (scentValue > 255 )
    {scentValue = 255;}
}


Scent::~Scent()
{

}