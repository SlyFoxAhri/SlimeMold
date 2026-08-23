#include <raylib.h>

class Button
{
    public:
        Button();
        Button(const char* title, Vector2 position);
        ~Button();
        const char* title;
        Vector2 position;
        Rectangle rectangle;
        void Draw();
        void Update(Color newColor);
        bool isClick(Vector2 mosePos, bool mousePressed);

};