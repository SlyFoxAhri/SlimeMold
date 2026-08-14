#include <raylib.h>
#include <raymath.h>
#include "cell.hpp"
#include <vector>
#include "iostream"

using namespace std;

int main(void)
{
    //int screenWidth = 800;
    //int screenHeight = 800;

    int cellsize = 20;
    int cellcount = 40;
    int cellNum = 1000;
    Cell celltarray[1000];

    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);

    
    
    Cell cell;
    for (int i = 0; i < cellNum; i++)
    {
        Cell cell;
        celltarray[i] = cell;
        cout << "ok: " << cell.direction.x << " " << cell.direction.y << endl;
    }
         

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
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