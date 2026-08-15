#include "scent.hpp"

Scent::Scent()
{
    scentValue = GetRandomValue(0, 255);
    scentColor = {0, 0, (unsigned char)scentValue, 255};
}

void Scent::Draw(int x, int y)
{
    DrawRectangle(x, y, 4, 4, scentColor);
}

Scent::~Scent()
{

}