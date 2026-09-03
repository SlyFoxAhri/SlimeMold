#include "../../include/core.hpp"

Core::Core(){}

Core::Core(int startPos, int edgeBvr)
{
    cellulNum = std::size(cellularray);
    scentLeftbyCellule=200;

    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            Scent scent;
            scentarray[i][j] = scent; 
        }
    }

    for (int i = 0; i < cellulNum; i++)
    {
        Cellule cellule {startPos, edgeBvr};
        cellularray[i] = cellule;
    }
}

void Core::Draw()
{
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].Draw(i*cellsize, j*cellsize); 
        }
    }

    for (auto cellule : cellularray)
    {
        cellule.Draw();
    }
}

void Core::Update()
{
    DiffuseScent();

    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].Update();
        }
    }

    for (int i = 0; i < cellulNum; i++)
    {
        cellularray[i].Update();
        LeaveScentTrail(i);
        Smell(&cellularray[i]);
    }
}

void Core::ClearScent()
{
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].SetScentvalue(-255);
        }
    }
}

void Core::Smell(Cellule* currentcell)
{
    Vector2 L = currentcell->leftSmeller;
    Vector2 R = currentcell->rightSmeller;
    Vector2 C = currentcell->centerSmeller;

    int currScentValL = scentarray[(int)(L.x)][(int)(L.y)].GetScentValue();
    int currScentValR = scentarray[(int)(R.x)][(int)(R.y)].GetScentValue();
    int currScentValC = scentarray[(int)(C.x)][(int)(C.y)].GetScentValue();

    if((currScentValL > currScentValR) & (currScentValL > currScentValC))
    {
        currentcell->SetDirection(Vector2Rotate(currentcell->direction, currentcell->turnAngle));
    }

    else if((currScentValR > currScentValL) & (currScentValR > currScentValC))
    {
        currentcell->SetDirection(Vector2Rotate(currentcell->direction, -(currentcell->turnAngle)));
    }
    /*
    else if(currScentValL == currScentValR)
    {
        int randTurn = GetRandomValue(0,1);
        if(randTurn==0) {currentcell->SetDirection(Vector2Rotate(currentcell->direction, currentcell->turnAngle));}
        else if(randTurn==1) {currentcell->SetDirection(Vector2Rotate(currentcell->direction, - (currentcell->turnAngle)));}   
    }
        */
}

void Core::LeaveScentTrail(int i)
{
    int posX = floor(cellularray[i].position.x)/cellsize;
    int posY = floor(cellularray[i].position.y)/cellsize;

    posX = ((posX+cellcount)%cellcount);
    posY = ((posY+cellcount)%cellcount);
    
    scentarray[posX][posY].ChangeScentvalue(scentLeftbyCellule);
}

void Core::DiffuseScent()
{
    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            temparray[i][j]=AvgScent(i,j);
        }
    }

    for (int i = 0; i < cellcount; i++)
    {
        for (int j = 0; j < cellcount; j++)
        {
            scentarray[i][j].SetScentvalue(temparray[i][j]);
        }
    }
}

int Core::AvgScent(int x, int y)
{
    int kernel[3][3] = {{1,1,1},{1,20,1},{1,1,1}};
    int divisor = 28;
    int a = 0;

    for( int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int tempX = (x + i)%cellcount;
            int tempY = (y + j)%cellcount; 
            
            int currentScentValue = scentarray[tempX][tempY].GetScentValue();
            a += currentScentValue*kernel[i+1][j+1];
        }
    }

    a = floor(a/divisor);
    return a;
}

Core::~Core()
{

}
