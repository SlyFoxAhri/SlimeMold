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
    buttonarray[2] = clearBtn;
    buttonarray[3] = resetBtn;
    buttonarray[4] = centralBtn;
    buttonarray[5] = scatteredBtn;
    buttonarray[6] = wrapBtn;
    buttonarray[7] = edgeBtn;
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


void Panel::Update()
{
    //buttons overlay?? 
    //ore everything in draw function??
}

void Panel::setButtonColor(Button *button)
{
    if(button == &centralBtn)
    {
        button->color = RED;
        Button* notBtn = &scatteredBtn;
        notBtn->color = GREEN;
    }
    else if(button == &scatteredBtn)
    {
        button->color = RED;
        Button* notBtn = &centralBtn;
        notBtn->color = GREEN;
    }
    else if(button == &wrapBtn)
    {
        button->color = RED;
        Button* notBtn = &edgeBtn;
        notBtn->color = GREEN;
    }
    else if (button == &edgeBtn)
    {
        button->color = RED;
        Button* notBtn = &wrapBtn;
        notBtn->color = GREEN;
    }

}

Panel::~Panel()
{

}
