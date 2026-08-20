#include "game.hpp"

Game::Game()
{
    cellulNum = 1000;
    turnAngle = 0.2*PI;
    //maxSmell = 12;

    maxSmell=100;
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
    for (int i = 0; i < cellulNum; i++)
    {
        Smell(&cellularray[i].leftSmeller, &cellularray[i].rightSmeller, &cellularray[i].centerSmeller, &cellularray[i].direction);
        CreateSmell(i);
        cellularray[i].Update();
    }

    //Diffuse();
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            //we need current cell position
            
            scentarray[i][j].Update();
            
        }
    }
}

void Game::Diffuse()
{
    //int kernel[3][3] = {{1,1,1},{1,4,1},{1,1,1}};

    int temparray[180][180];

    //populate entire temparray
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            //temparray[i][j]=scentarray[i][j].scentValue; //average this
            temparray[i][j]=Avg(i,j); 
            //why is this needed???
            if (temparray[i][j] > 255) {temparray[i][j] = 255;} 
        }
    }

    //assign each cell from temparray to scnetarray
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].scentValue = temparray[i][j];
            //scentarray[i][j].addtoScentValue(temparray[i][j]); 
        }
    }
}

int Game::Avg(int x, int y)
{
    int divisor = 12;
    int a = 0;

    for( int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int tempX = x + i;
            if(tempX > cellcount) {tempX = 0;}
            if(tempX < 0) {tempX = cellcount;}

            int tempY = y + j; 
            if(tempY > cellcount) {tempY = 0;}
            if(tempY < 0) {tempY = cellcount;}
            
            a += scentarray[tempX][tempY].scentValue;
        }
    }
    a = floor(a/9);
    return a;
};

void Game::CreateSmell(int iterator)
{
    int posX = floor(cellularray[iterator].position.x)/cellsize;
    int posY = floor(cellularray[iterator].position.y)/cellsize;

    posX = ((posX+cellcount)%cellcount);
    posY = ((posY+cellcount)%cellcount);
    
    //turnicate both scentvalue and location to inside accept range
    
    scentarray[posX][posY].addtoScentValue(maxSmell);
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