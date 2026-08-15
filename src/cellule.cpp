#include "cellule.hpp"
#include "iostream"

Cellule::Cellule()
{
    randomPosX = (float)GetRandomValue(0,cellcount*cellsize);
    randomPosY = (float)GetRandomValue(0,cellcount*cellsize);
    position = {randomPosX, randomPosY};

    randomRotateAngle = (GetRandomValue(0, 360))/PI;
    direction = {1.0, 1.0};
    direction = Vector2Rotate(direction, randomRotateAngle);

    speed = 10;
    color = RED;

    //play with values
    senseAngle = 0.2*PI;
    senseLength = 10;
}

void Cellule::Draw()
{
    DrawRectangle(position.x-cellsize*0.5, position.y-cellsize*0.5, cellsize, cellsize, color);
    //DrawLine(position.x, position.y, position.x+(direction.x*10), position.y+(direction.y*10), GREEN);
    //rotate it!!!
    //DrawRectanglePro(rec, position, randomRotateAngle, color);

    //std::cout << position.x << " " << position.y << " " << direction.x << " " << direction.y << std::endl;
    
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

    //std::cout << "x: " << position.x << " " << "y: " << position.y <<  " " << "dir: " << direction.x << " " << direction.y << std::endl;
    
}

Vector2 Cellule::SensePositon(float angle)
{
    Vector2 sceentPosition;
    Vector2 returnPosition;

    sceentPosition = Vector2Add(position , (Vector2Rotate(direction, angle)*senseLength));
    
    sceentPosition.x = (int)(sceentPosition.x+GetScreenWidth())%GetScreenWidth();
    sceentPosition.y = (int)(sceentPosition.y+GetScreenHeight())%GetScreenHeight();
    //DrawCircle(sceentPosition.x, sceentPosition.y, 2.0, GREEN);
    
    float x = sceentPosition.x;
    float y = sceentPosition.y;

    x = floor(x/cellsize);
    y = floor(y/cellsize);

    x = (int)x%cellcount;
    y = (int)y%cellcount;

    return returnPosition = {x, y};
}

Cellule::~Cellule()
{

}