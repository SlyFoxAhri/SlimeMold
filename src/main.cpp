#include "game.hpp"
#include "iostream"

using namespace std;

int main(void)
{   
    Game game;
    
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(1);
        
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