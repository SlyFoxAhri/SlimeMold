#include "game.hpp"

Game::Game()
{
    cellNum = 1000;

    for (int i = 0; i < cellNum; i++)
    {
        Cell cell;
        cellarray[i] = cell;
    }
}

void Game::HandleInput()
{
    //state stopped or started -> space
    //objects on the screen can be clicked 
    //this will be used to select what is being put down
    //food with scent or obsticle
}

void Game::Draw()
{
    scent.Draw();

    for (int i = 0; i < cellNum; i++)
    {
        cellarray[i].Draw();
        cellarray[i].Update();
    }

}

Game::~Game()
{

}