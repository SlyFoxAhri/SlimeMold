#include "game.hpp"

Game::Game()
{
    cellulNum = 1000;
    turnAngle = 0.2*PI;
    maxSmell = 255;
    diffusedsmell = 10;

    //create cellules
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
    if(IsKeyPressed(KEY_SPACE))
    {
        if(isPaused)
        {isPaused = false;}
        else{isPaused = true;}
    }
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
        
    }
}

void Game::Update()
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            scentarray[i][j].Update();
        }
        
    }
    
    for (int i = 0; i < cellulNum; i++)
    {
        Smell(&cellularray[i].leftSmeller, &cellularray[i].rightSmeller, &cellularray[i].centerSmeller, &cellularray[i].direction);
        CreateSmell(i);
        cellularray[i].Update();
    }
}

void Game::CreateSmell(int iterator)
{
    int posX = (cellularray[iterator].position.x)/cellsize;
    int posY = (cellularray[iterator].position.y)/cellsize;


    posX = (posX+cellcount)%cellcount;
    posY = (posY+cellcount)%cellcount;
    
    //turnicate both scentvalue and location to inside accept range
    scentarray[posX][posY].addtoScentValue(maxSmell);
    scentarray[posX+1][posY+1].addtoScentValue(diffusedsmell);
    scentarray[posX+1][posY].addtoScentValue(diffusedsmell);
    scentarray[posX+1][posY-1].addtoScentValue(diffusedsmell);
    scentarray[posX][posY+1].addtoScentValue(diffusedsmell);
    scentarray[posX][posY].addtoScentValue(diffusedsmell);
    scentarray[posX][posY-1].addtoScentValue(diffusedsmell);
    scentarray[posX-1][posY+1].addtoScentValue(diffusedsmell);
    scentarray[posX-1][posY].addtoScentValue(diffusedsmell);
    scentarray[posX+1][posY-1].addtoScentValue(diffusedsmell);

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

Game::~Game()
{

}