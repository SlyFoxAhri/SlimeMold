#include "game.hpp"
#include "iostream"

Game::Game()
{
    cellulNum = 10;
    changeAmount = 10;
    turnAngle = 0.2*PI;

    //create units
    for (int i = 0; i < cellulNum; i++)
    {
        Cellule cellule;
        cellularray[i] = cellule;
    }

    //create scents
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            Scent scent;
            scentarray[i][j] = scent; 
        }
    }
        
}

void Game::HandleInput()
{
    //state stopped or started -> space
    //objects on the screen can be clicked 
    //this will be used to select what is being put down
    //food with scent or obsticle
}

void Game::Draw()
{
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].Draw(i*cellsize, j*cellsize); 
        }
    }

    for (int i = 0; i < cellulNum; i++)
    {
        cellularray[i].Draw();
        
        
        
        cellularray[i].Sense();

        //FollowSmell();
        /*
        int posX = (cellularray[i].position.x)/cellsize;
        int posY = (cellularray[i].position.y)/cellsize;

        if(posX > 200)
        {posX = 0;}
        if(posX < 0)
        {posX = 200;}
        if(posY > 200)
        {posY = 0;}
        if(posY < 0)
        {posY = 200;}

        scentarray[posX][posY].scentValue = 255;
        */

        //may not work properly or needs to be fine tuned
        //Smell(&cellularray[i].leftSmeller, &cellularray[i].rightSmeller, &cellularray[i].centerSmeller, &cellularray[i].direction);
        cellularray[i].Update();

    }
}


void Game::Smell(Vector2* L, Vector2* R, Vector2* C, Vector2* dir)
{
    int currScentValL = scentarray[(int)(L->x)][(int)(L->y)].scentValue;
    int currScentValR = scentarray[(int)(R->x)][(int)(R->y)].scentValue;
    int currScentValC = scentarray[(int)(C->x)][(int)(C->y)].scentValue;

    if((currScentValL > currScentValR) & (currScentValL > currScentValC))
    {
        *dir = Vector2Rotate(*dir, turnAngle);
    }

    if((currScentValR > currScentValL) & (currScentValR > currScentValC))
    {
        *dir = Vector2Rotate(*dir, -turnAngle);
    }
}
/*
void Game::FollowSmell()
{
    int posX = (cellularray[i].position.x)/cellsize;
        int posY = (cellularray[i].position.y)/cellsize;

        if(posX > 200)
        {posX = 0;}
        if(posX < 0)
        {posX = 200;}
        if(posY > 200)
        {posY = 0;}
        if(posY < 0)
        {posY = 200;}

        scentarray[posX][posY].scentValue = 255;
}
        */

void Game::Update()
{

}

Game::~Game()
{

}