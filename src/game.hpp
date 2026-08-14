#include <raylib.h>
#include "cell.hpp"
#include "scent.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        int cellNum;
        Cell cellarray[1000];
        Scent scent;
    private:


    
};