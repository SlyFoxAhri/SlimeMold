#include "cellule.hpp"
#include "iostream"

Cellule::Cellule()
{
    randomPosX = (float)GetRandomValue(0,800);
    randomPosY = (float)GetRandomValue(0,800);
    position = {randomPosX, randomPosY};

    randomRotateAngle = (GetRandomValue(0, 360))/PI;
    direction = {1.0, 1.0};
    direction = Vector2Rotate(direction, randomRotateAngle);

    speed = 5;
    color = RED;

    //play with values
    senseAngle = 0.2*PI;
    senseLength = 5;
    turnAngle = 0.2*PI;
}

void Cellule::Draw()
{
    DrawRectangle(position.x-cellsize*0.5, position.y-cellsize*0.5, cellsize, cellsize, color);

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

    if(position.x >= GetScreenWidth() && position.x < 0)
    {position.x = 0;}

    if(position.y >= GetScreenHeight() && position.y < 0)
    {position.y = 0;}

    //std::cout << "x: " << position.x << " " << "y: " << position.y <<  " " << "dir: " << direction.x << " " << direction.y << std::endl;
    
}

Vector2 Cellule::SensePositon(float angle)
{
    Vector2 sceentPosition;

    float x = position.x+senseLength*cosf(direction.x+angle);
    float y = position.y+senseLength*sinf(direction.y+angle);

    if(x >= GetScreenWidth())
    {x = 0;}

    if(y >= GetScreenHeight())
    {y = 0;}

    x = floor(x/cellsize);
    y = floor(y/cellsize);

    x = (int)x%cellcount;
    y = (int)y%cellcount;

    return sceentPosition = {x, y};
}

Cellule::~Cellule()
{

}