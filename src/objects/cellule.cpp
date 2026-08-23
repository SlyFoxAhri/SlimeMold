#include "cellule.hpp"

Cellule::Cellule()
{
    float randomPosX = (float)GetRandomValue(0,cellcount*cellsize);
    float randomPosY = (float)GetRandomValue(0,cellcount*cellsize);
    position = {randomPosX, randomPosY};

    float randomRotateAngle = (GetRandomValue(1, 360))/PI;
    direction = Vector2Rotate({1.0, 1.0}, randomRotateAngle);

    color = RED;
    speed = 3*cellsize;
    
    //play with values
    senseAngle = 0.1*PI;
    turnAngle = 0.2*PI;
    senseLength = 3*cellsize;
}

void Cellule::Draw()
{
    DrawCircle(position.x, position.y, cellsize, color);
}

void Cellule::Update()
{
    Sense();

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

void Cellule::SetDirection(Vector2 newPos)
{
    direction = newPos;
}

void Cellule::Sense()
{
    //coordinate of sensor in grid
    leftSmeller = SensePositon(senseAngle);
    rightSmeller = SensePositon(-senseAngle);
    centerSmeller = SensePositon(0);
    /*
    DrawCircle(leftSmeller.x*cellsize, leftSmeller.y*cellsize, 1, PINK);
    DrawCircle(rightSmeller.x*cellsize, rightSmeller.y*cellsize, 1, PINK);
    DrawCircle(centerSmeller.x*cellsize, centerSmeller.y*cellsize, 1, PINK);
    */
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