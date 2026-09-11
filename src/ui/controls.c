/*******************************************************************************************
*
*   LayoutName v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../../include/raygui.h"
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_name");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *GroupBox000Text = "Control panel";    // GROUPBOX: GroupBox000
    const char *DropdownBox001Text = "Agent;Enviromet;Draw";    // DROPDOWNBOX: DropdownBox001
    const char *ToggleGroup002Text = "Start;Stop;Reset";    // TOGGLEGROUP: ToggleGroup002
    const char *SliderBar004Text = "";    // SLIDERBAR: SliderBar004
    const char *SliderBar005Text = "";    // SLIDERBAR: SliderBar005
    const char *Label006Text = "Size";    // LABEL: Label006
    const char *Label007Text = "Speed";    // LABEL: Label007
    const char *CheckBoxEx010Text = "Directional noise";    // CHECKBOXEX: CheckBoxEx010
    const char *SliderBar010Text = "";    // SLIDERBAR: SliderBar010
    const char *SliderBar011Text = "";    // SLIDERBAR: SliderBar011
    const char *Label012Text = "Sensor distance";    // LABEL: Label012
    const char *Label013Text = "Sensor angle";    // LABEL: Label013
    const char *Label014Text = "Turn angle";    // LABEL: Label014
    const char *SliderBar015Text = "";    // SLIDERBAR: SliderBar015
    const char *Label016Text = "Number of agents";    // LABEL: Label016
    
    // Define anchors
    Vector2 anchor01 = { 216, 112 };            // ANCHOR ID:1
    
    // Define controls variables
    bool DropdownBox001EditMode = false;
    int DropdownBox001Active = 0;            // DropdownBox: DropdownBox001
    int ToggleGroup002Active = 0;            // ToggleGroup: ToggleGroup002
    Color ColorPicker003Value = { 0, 0, 0, 0 };            // ColorPicker: ColorPicker003
    float SliderBar004Value = 0.0f;            // SliderBar: SliderBar004
    float SliderBar005Value = 0.0f;            // SliderBar: SliderBar005
    bool CheckBoxEx010Checked = false;            // CheckBoxEx: CheckBoxEx010
    float SliderBar010Value = 0.0f;            // SliderBar: SliderBar010
    float SliderBar011Value = 0.0f;            // SliderBar: SliderBar011
    float SliderBar015Value = 0.0f;            // SliderBar: SliderBar015
    bool ValueBOx015EditMode = false;
    int ValueBOx015Value = 0;            // ValueBOx: ValueBOx015

    // Define controls rectangles
    Rectangle layoutRecs[17] = {
        (Rectangle){ anchor01.x + 0, anchor01.y + 8, 280, 256 },    // GroupBox: GroupBox000
        (Rectangle){ anchor01.x + 8, anchor01.y + 16, 120, 24 },    // DropdownBox: DropdownBox001
        (Rectangle){ anchor01.x + 48, anchor01.y + 224, 64, 24 },    // ToggleGroup: ToggleGroup002
        (Rectangle){ anchor01.x + 144, anchor01.y + 16, 96, 96 },    // ColorPicker: ColorPicker003
        (Rectangle){ anchor01.x + 8, anchor01.y + 64, 120, 16 },    // SliderBar: SliderBar004
        (Rectangle){ anchor01.x + 8, anchor01.y + 96, 120, 16 },    // SliderBar: SliderBar005
        (Rectangle){ anchor01.x + 8, anchor01.y + 48, 120, 16 },    // Label: Label006
        (Rectangle){ anchor01.x + 8, anchor01.y + 80, 120, 16 },    // Label: Label007
        (Rectangle){ anchor01.x + 144, anchor01.y + 128, 24, 24 },    // CheckBoxEx: CheckBoxEx010
        (Rectangle){ anchor01.x + 8, anchor01.y + 128, 120, 16 },    // SliderBar: SliderBar010
        (Rectangle){ anchor01.x + 8, anchor01.y + 160, 120, 16 },    // SliderBar: SliderBar011
        (Rectangle){ anchor01.x + 8, anchor01.y + 112, 120, 16 },    // Label: Label012
        (Rectangle){ anchor01.x + 8, anchor01.y + 144, 120, 16 },    // Label: Label013
        (Rectangle){ anchor01.x + 8, anchor01.y + 176, 120, 16 },    // Label: Label014
        (Rectangle){ anchor01.x + 8, anchor01.y + 192, 120, 16 },    // SliderBar: SliderBar015
        (Rectangle){ anchor01.x + 144, anchor01.y + 184, 120, 24 },    // ValueBOx: ValueBOx015
        (Rectangle){ anchor01.x + 144, anchor01.y + 168, 120, 16 },    // Label: Label016
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            if (DropdownBox001EditMode) GuiLock();

            GuiGroupBox(layoutRecs[0], GroupBox000Text);
            GuiToggleGroup(layoutRecs[2], ToggleGroup002Text, &ToggleGroup002Active);
            GuiColorPicker(layoutRecs[3], ColorPicker003Text, &ColorPicker003Value);
            GuiSliderBar(layoutRecs[4], SliderBar004Text, NULL, &SliderBar004Value, 0, 100);
            GuiSliderBar(layoutRecs[5], SliderBar005Text, NULL, &SliderBar005Value, 0, 100);
            GuiLabel(layoutRecs[6], Label006Text);
            GuiLabel(layoutRecs[7], Label007Text);
            GuiCheckBox(layoutRecs[8], CheckBoxEx010Text, &CheckBoxEx010Checked);
            GuiSliderBar(layoutRecs[9], SliderBar010Text, NULL, &SliderBar010Value, 0, 100);
            GuiSliderBar(layoutRecs[10], SliderBar011Text, NULL, &SliderBar011Value, 0, 100);
            GuiLabel(layoutRecs[11], Label012Text);
            GuiLabel(layoutRecs[12], Label013Text);
            GuiLabel(layoutRecs[13], Label014Text);
            GuiSliderBar(layoutRecs[14], SliderBar015Text, NULL, &SliderBar015Value, 0, 100);
            if (GuiValueBox(layoutRecs[15], ValueBOx015Text, &ValueBOx015Value, 0, 100, ValueBOx015EditMode)) ValueBOx015EditMode = !ValueBOx015EditMode;
            GuiLabel(layoutRecs[16], Label016Text);
            if (GuiDropdownBox(layoutRecs[1], DropdownBox001Text, &DropdownBox001Active, DropdownBox001EditMode)) DropdownBox001EditMode = !DropdownBox001EditMode;
            
            GuiUnlock();
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

