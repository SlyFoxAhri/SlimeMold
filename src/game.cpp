#include "../include/game.hpp"

Game::Game()
{
    startPosition = SCATTER_START; edgeBehaviour = WRAP;
    gameCore = std::make_unique<Core>(startPosition, edgeBehaviour);
    isPaused = false;
    isPanelShown = false;
}

void Game::HandleInput()
{
    isLeftMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    isRightMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
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
    if(IsKeyPressed(KEY_X))
    {
        if(isPanelShown)
        {isPanelShown = false;}
        else{isPanelShown = true;}
    }
    if(panel.startBtn.isClick(GetMousePosition(), isLeftMousePressed)) {isPaused = false;}
    if(panel.stopBtn.isClick(GetMousePosition(), isLeftMousePressed)) {isPaused = true;}
    if(panel.clearBtn.isClick(GetMousePosition(), isLeftMousePressed)) {gameCore->ClearScent();}
    if(panel.resetBtn.isClick(GetMousePosition(), isLeftMousePressed)) {gameCore.reset(new Core(startPosition, edgeBehaviour)); isPaused = false;}
    if(panel.centralBtn.isClick(GetMousePosition(), isLeftMousePressed)) {startPosition = CENTER_START; panel.setButtonColor(&panel.centralBtn);}
    if(panel.scatteredBtn.isClick(GetMousePosition(), isLeftMousePressed)) {startPosition = SCATTER_START; panel.setButtonColor(&panel.scatteredBtn);}
    if(panel.wrapBtn.isClick(GetMousePosition(), isLeftMousePressed)) {edgeBehaviour = WRAP; panel.setButtonColor(&panel.wrapBtn);}
    if(panel.edgeBtn.isClick(GetMousePosition(), isLeftMousePressed)) {edgeBehaviour = EDGE; panel.setButtonColor(&panel.edgeBtn);}

}

void Game::Draw()
{
    gameCore->Draw();
}

void Game::Update()
{
    if(!isPaused)
    {gameCore->Update();}
    if(isPanelShown)
    {panel.Draw();}
}

Game::~Game()
{

}