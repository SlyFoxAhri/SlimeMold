#include <raylib.h>
#include "global.hpp"

class Button
{
    public:
        Button();
        Button(const char* title, Vector2 position);
        ~Button();
        const char* title;
        Vector2 position;
        Rectangle rectangle;
        Color color; 
        Color* colorPtr;
        bool isClicked;
        void Draw();
        void Update(Color newColor);
        bool isClick(Vector2 mosePos, bool mousePressed);
        
};