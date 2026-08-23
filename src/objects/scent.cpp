#include "scent.hpp"

Scent::Scent()
{
    scentValue = 0;
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    evaporationValue = -5;
}

void Scent::Draw(int x, int y)
{
    scentColor = {0, 0, (unsigned char)scentValue, 255};
    DrawRectangle(x, y, 4, 4, scentColor);
}

void Scent::Update()
{
    ChangeScentvalue(evaporationValue);
}

int Scent::GetScentValue()
{
    return scentValue;
}

void Scent::SetScentvalue(int newValue)
{
    scentValue = newValue;
}

void Scent::ChangeScentvalue(int changeValue)
{
    scentValue += changeValue;
    if(scentValue < 0) {scentValue = 0;}
    else if(scentValue > 255) {scentValue = 255;}
}

Scent::~Scent()
{

}