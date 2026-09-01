#include "panel.hpp"

Panel::Panel()
{
    position = {(float)(cellsize*2),(float)(cellsize*2)};
    width = cellsize*40;
    height = cellsize*50;
    color = {120, 120, 120, 255};

    title = "Slime Mold Controls";
    line = "--------------------";
    startPosition = "Start position";
    edgeBehaviour = "Container behaviour";
    howDoIHudeUi = "Press X to hide UI";
    textColor = {200, 200, 200, 255};
    fontSize = 10;

    //buttonarray[7] = {startBtn, stopBtn, resetBtn, centralBtn, scatteredBtn, wrapBtn, edgeBtn};
    
    buttonarray[0] = startBtn;
    buttonarray[1] = stopBtn;
    buttonarray[2] = resetBtn;
    buttonarray[3] = centralBtn;
    buttonarray[4] = scatteredBtn;
    buttonarray[5] = wrapBtn;
    buttonarray[6] = edgeBtn;
}

void Panel::Draw()
{
    DrawRectangle(position.x, position.y, width, height, color);
    DrawText(title, position.x + 10, position.y + 10, fontSize, textColor);
    DrawText(line, position.x + 10, position.y + 20, fontSize, textColor);
    DrawText(startPosition, position.x + 10, position.y + 30, fontSize, textColor);
    DrawText(edgeBehaviour, position.x + 10, position.y + 80, fontSize, textColor);
    DrawText(howDoIHudeUi, position.x + 10, position.y + 130, fontSize, textColor);

    
    for(auto i : buttonarray)
    {
        i.Draw();
    }
}

void Panel::HandleInput()
{
    //Vector2 mousePos = GetMousePosition();
    //isLeftMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    //isRightMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
//
    //if(startBtn.isClick(GetMousePosition(), isLeftMousePressed)) {std::cout << "start" << std::endl;}
    //if(stopBtn.isClick(GetMousePosition(), isLeftMousePressed)) {std::cout << "stop" << std::endl;}
    //if(resetBtn.isClick(GetMousePosition(), isLeftMousePressed)) {}
    //if(centralBtn.isClick(GetMousePosition(), isLeftMousePressed)) {}
    //if(scatteredBtn.isClick(GetMousePosition(), isLeftMousePressed)) {}
    //if(wrapBtn.isClick(GetMousePosition(), isLeftMousePressed)) {}
    //if(edgeBtn.isClick(GetMousePosition(), isLeftMousePressed)) {}

}

void Panel::Update()
{
    //buttons overlay?? 
    //ore everything in draw function??
}

Panel::~Panel()
{

}
