#include <raylib.h>

class Scent
{
    public:
        Scent();
        ~Scent();
        int cellcount;
        int x;
        int y;
        Color scentColorarray[200][200];
        void Draw();
        void Update();
        Color GetColor();
        Color scentColor;

    private:
};