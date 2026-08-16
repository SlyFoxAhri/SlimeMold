#include "game.hpp"

int main(void)
{   
    Game game;
    
    InitWindow(cellsize*cellcount, cellsize*cellcount, "Slime Mold Enclosure");
    SetTargetFPS(20);
        
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
      
        game.HandleInput();
        game.Draw();
        if(!isPaused)
        {game.Update();}
    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}