#include "game.hpp"

Game::Game()
{
    isPaused = false;
    isPanelShown = true;
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
    panel.HandleInput();
}

void Game::Draw()
{
    gameCore.Draw();
    
}

void Game::Update()
{
    if(!isPaused)
    {gameCore.Update();}
    if(isPanelShown)
    {panel.Draw();}
}

Game::~Game()
{

}