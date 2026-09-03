#pragma once
#include <raylib.h>
#include <string>
#include "button.hpp"
#include "global.hpp"


class Panel
{
    public:
        Panel();
        ~Panel();
        void Draw();
        void Update();
        Button startBtn{"Start", {18.0f, 150.0f}};
        Button stopBtn{"Stop", {48.0f, 150.0f}};
        Button clearBtn{"Clear", {78.0f, 150.0f}};
        Button resetBtn{"Reset", {108.0f, 150.0f}};
        Button centralBtn{"Central", {18.0f, 50.0f}};
        Button scatteredBtn{"Scattered", {48.0f, 50.0f}};
        Button wrapBtn{"Wrap", {18.0f, 100.0f}};
        Button edgeBtn{"Edge", {48.0f, 100.0f}};
        void setButtonColor(Button* button);
    private:
        Vector2 position;
        int width;
        int height;
        Color color;
        const char* title;
        const char* line;
        const char* startPosition;
        const char* edgeBehaviour;
        const char* howDoIHudeUi;
        int fontSize;
        Color textColor;
        Button buttonarray[8];
        bool isLeftMousePressed;
        bool isRightMousePressed;
        
    };