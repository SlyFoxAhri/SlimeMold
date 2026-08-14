#include "scent.hpp"

Scent::Scent()
{
    
}

Scent::~Scent()
{

}

void Scent::Draw()
{
    Color scentColor = {0,0,GetRandomValue(0,255),255};
    DrawRectangle(x, y, 4, 4, scentColor);
}