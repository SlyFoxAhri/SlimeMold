#include <raylib.h>
#include <raymath.h>
#include "cell.hpp"
#include "scent.hpp"
#include "iostream"

using namespace std;

int main(void)
{
    int cellsize = 4;
    int cellcount = 200;
    int cellNum = 1000;
    Cell celltarray[1000];
    Scent scentarray[200][200];

    
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);

    
    for (int i = 0; i < cellNum; i++)
    {
        Cell cell;
        celltarray[i] = cell;
        cout << "ok: " << cell.direction.x << " " << cell.direction.y << endl;
    }

    for (int i = 0; i < cellcount; i = i + 5)
    {
        for (int j = 0; j < cellcount; j = j + 5)
        {
            Scent scent;
            scent.x = i; scent.y =j;
            scentarray[i][j] = scent;
            scentarray[i][j].Draw(); 
        }
        
    }
         

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        

        //cells
        for (int i = 0; i < cellNum; i++)
        {
            celltarray[i].Draw();
            celltarray[i].Update();
        }

        for (int i = 0; i < cellcount; i = i + 5)
    {
        for (int j = 0; j < cellcount; j = j + 5)
        {
            Scent scent;
            scent.x = i; scent.y =j;
            scentarray[i][j] = scent;
            scentarray[i][j].Draw(); 
        }
        
    }
        
        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}