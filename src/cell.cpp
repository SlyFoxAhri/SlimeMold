#include "cell.hpp"

Cell::Cell()
{
    randomPosX = (float)GetRandomValue(0,800);
    randomPosY = (float)GetRandomValue(0,800);
    position = {randomPosX, randomPosY};

    randomRotateAngle = (float)GetRandomValue(0, 360);  
    direction = {1.0, 1.0};
    direction = Vector2Rotate(direction, randomRotateAngle);

    speed = 5;
    color = RED;
}

void Cell::Draw()
{
    DrawRectangle(position.x, position.y, 5, 5, color);

    //rotate it!!!
    //DrawRectanglePro(rec, position, randomRotateAngle, color);
    
}

void Cell::Update()
{
    position.x += direction.x*speed*GetFrameTime();
    position.y += direction.y*speed*GetFrameTime();

    if(position.x >= GetScreenWidth())
    {position.x = 0.0;}

    if(position.y >= GetScreenHeight())
    {position.y = 0.0;}
}

Cell::~Cell()
{

}