#include <raylib.h>
#include <raymath.h>
#include "game.hpp"
#include "iostream"

using namespace std;

int main(void)
{
    int cellsize = 4;
    int cellcount = 200;
    Game game;
    
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);
        
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
      
        game.HandleInput();
        game.Draw();
    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}