#include "game.hpp"

int main(void)
{   
    int cellsize = 4;
    int cellcount = 180;
    Game game;
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);

    
        
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
      
        game.HandleInput();
        game.Draw();
        game.Update();
    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}