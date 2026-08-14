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
    Scent scent;

    
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);

    
    for (int i = 0; i < cellNum; i++)
    {
        Cell cell;
        celltarray[i] = cell;
        cout << "ok: " << cell.direction.x << " " << cell.direction.y << endl;
    }

    
    //nnow we have filled a colorarray
         

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        scent.Draw();        

        //cells
        for (int i = 0; i < cellNum; i++)
        {
            celltarray[i].Draw();
            celltarray[i].Update();
        }

        
        
        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}