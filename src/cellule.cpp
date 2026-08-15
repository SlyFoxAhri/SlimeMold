#include "cellule.hpp"

Cellule::Cellule()
{
    randomPosX = (float)GetRandomValue(0,cellcount*cellsize);
    randomPosY = (float)GetRandomValue(0,cellcount*cellsize);
    position = {randomPosX, randomPosY};

    randomRotateAngle = (GetRandomValue(0, 360))/PI;
    direction = Vector2Rotate({1.0, 1.0}, randomRotateAngle);

    speed = 20;
    color = RED;

    //play with values
    senseAngle = 0.2*PI;
    senseLength = 30;
}

void Cellule::Draw()
{
    DrawCircle(position.x, position.y, cellsize, color);
    //rotate it!!!
    //DrawRectanglePro(rec, position, randomRotateAngle, color);
}

void Cellule::Sense()
{
    //coordinate of sensor in grid
    leftSmeller = SensePositon(senseAngle);
    rightSmeller = SensePositon(-senseAngle);
    centerSmeller = SensePositon(0);
}

void Cellule::Update()
{
    position.x += direction.x*speed*GetFrameTime();
    position.y += direction.y*speed*GetFrameTime();
    
    if(position.x >= GetScreenWidth())
    {position.x = 0;}
    if(position.x < 0)
    {position.x = GetScreenWidth();}

    if(position.y >= GetScreenHeight())
    {position.y = 0;}
    if(position.y < 0)
    {position.y = GetScreenHeight();}
    
}

Vector2 Cellule::SensePositon(float angle)
{
    Vector2 sceentPosition;

    sceentPosition = Vector2Add(position , (Vector2Rotate(direction, angle)*senseLength));
    
    sceentPosition.x = (int)(sceentPosition.x+GetScreenWidth())%GetScreenWidth();
    sceentPosition.y = (int)(sceentPosition.y+GetScreenHeight())%GetScreenHeight();
    
    float x = sceentPosition.x;
    float y = sceentPosition.y;

    x = floor(x/cellsize);
    y = floor(y/cellsize);

    x = (int)x%cellcount;
    y = (int)y%cellcount;

    return sceentPosition = {x, y};
}

Cellule::~Cellule()
{

}