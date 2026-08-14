#include <raylib.h>

class Scent
{
    public:
        Scent();
        ~Scent();
        int cellcount;
        Color scentColorarray[200][200];
        void Draw();
        void Update();

    private:
};