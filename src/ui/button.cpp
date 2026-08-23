#include "button.hpp"

Button::Button()
{}

Button::Button(const char* title, Vector2 position)
{
    this->title = title;
    this->position = position;
    rectangle = {position.x, position.y, 20, 20};
}


bool Button::isClick(Vector2 mosePos, bool mousePressed)
{
    if(CheckCollisionPointRec(mosePos, rectangle) && mousePressed) {return true;}
    return false;
}

void Button::Draw()
{
    DrawRectangleRec(rectangle, GREEN);
    DrawText(title, position.x, position.y, 10, BLACK);
}


Button::~Button()
{

}