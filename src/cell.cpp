#include "cell.hpp"

Cell::Cell()
{
    randomPosX = (float)GetRandomValue(0,800);
    randomPosY = (float)GetRandomValue(0,800);
    position = {randomPosX, randomPosY};

    randomRotateAngle = (GetRandomValue(0, 360))/PI;
    direction = {1.0, 1.0};
    direction = Vector2Rotate(direction, randomRotateAngle);

    speed = 10;
    color = RED;

    //play with values
    senseAngle = 0.2*PI;
    senseLength = 10;
    turnAngle = 0.2*PI;
}

void Cell::Draw()
{
    DrawRectangle(position.x, position.y, 5, 5, color);

    //rotate it!!!
    //DrawRectanglePro(rec, position, randomRotateAngle, color);
    
}

void Cell::Update()
{
    
    leftSmeller = GetScent(senseAngle);
    rightSmeller = GetScent(-senseAngle);
    centerSmeller = GetScent(0);
    

    position.x += direction.x*speed*GetFrameTime();
    position.y += direction.y*speed*GetFrameTime();

    if(position.x >= GetScreenWidth())
    {position.x = 0.0;}

    if(position.y >= GetScreenHeight())
    {position.y = 0.0;}
    
}
//return vector of xy
float Cell::GetScent(float angle)
{
    float x = position.x+senseLength*cosf(direction.x+angle);
    float y = position.y+senseLength*sinf(direction.y+angle);

    if(x >= GetScreenWidth())
    {x = 0;}

    if(y >= GetScreenHeight())
    {y = 0;}

    //how to avoid errors with float?
    //in theory i get coordinates -> do test
    x = floor(x/cellsize);
    y = floor(y/cellsize);

    //now we have x y coordinates of the scents
    //we have to check if the color value of the blue is bigger
    //we should do this inside game?
    x = (int)x%cellcount;
    y = (int)y%cellcount;

    float testreturnvalue = 2.0; 
    return testreturnvalue;

}

Cell::~Cell()
{

}