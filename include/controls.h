/*******************************************************************************************
*
*   ControlPanel v1.0.0 - Tool Description
*
*   MODULE USAGE:
*       #define GUI_CONTROL_PANEL_IMPLEMENTATION
*       #include "gui_Control_panel.h"
*
*       INIT: GuiControlPanelState state = InitGuiControlPanel();
*       DRAW: GuiControlPanel(&state);
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

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_CONTROL_PANEL_H
#define GUI_CONTROL_PANEL_H

typedef struct {
    // Define anchors
    Vector2 anchor01;            // ANCHOR ID:1
    
    // Define controls variables
    bool DropdownBox001EditMode;
    int DropdownBox001Active;            // DropdownBox: DropdownBox001
    int ToggleGroup002Active;            // ToggleGroup: ToggleGroup002
    Color AgentColorpickerValue;            // ColorPicker: AgentColorpicker
    float SliderBar004Value;            // SliderBar: SliderBar004
    float SliderBar005Value;            // SliderBar: SliderBar005
    bool CheckBoxEx010Checked;            // CheckBoxEx: CheckBoxEx010
    float SliderBar010Value;            // SliderBar: SliderBar010
    float SliderBar011Value;            // SliderBar: SliderBar011
    float SliderBar015Value;            // SliderBar: SliderBar015
    bool ValueBOx015EditMode;
    int ValueBOx015Value;            // ValueBOx: ValueBOx015

    // Define rectangles
    Rectangle layoutRecs[17];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiControlPanelState;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiControlPanelState InitGuiControlPanel(void);
void GuiControlPanel(GuiControlPanelState *state);


#ifdef __cplusplus
}
#endif

#endif // GUI_CONTROL_PANEL_H

/***********************************************************************************
*
*   GUI_CONTROL_PANEL IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_CONTROL_PANEL_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiControlPanelState InitGuiControlPanel(void)
{
    GuiControlPanelState state = { 0 };

    // Init anchors
    state.anchor01 = (Vector2){ 216, 112 };            // ANCHOR ID:1
    
    // Initilize controls variables
    state.DropdownBox001EditMode = false;
    state.DropdownBox001Active = 0;            // DropdownBox: DropdownBox001
    state.ToggleGroup002Active = 0;            // ToggleGroup: ToggleGroup002
    state.AgentColorpickerValue = (Color){ 0, 0, 0, 0 };            // ColorPicker: AgentColorpicker
    state.SliderBar004Value = 0.0f;            // SliderBar: SliderBar004
    state.SliderBar005Value = 0.0f;            // SliderBar: SliderBar005
    state.CheckBoxEx010Checked = false;            // CheckBoxEx: CheckBoxEx010
    state.SliderBar010Value = 0.0f;            // SliderBar: SliderBar010
    state.SliderBar011Value = 0.0f;            // SliderBar: SliderBar011
    state.SliderBar015Value = 0.0f;            // SliderBar: SliderBar015
    state.ValueBOx015EditMode = false;
    state.ValueBOx015Value = 0;            // ValueBOx: ValueBOx015

    // Init controls rectangles
    state.layoutRecs[0] = (Rectangle){ state.anchor01.x + 0, state.anchor01.y + 8, 280, 256 };// GroupBox: GroupBox000
    state.layoutRecs[1] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 16, 120, 24 };// DropdownBox: DropdownBox001
    state.layoutRecs[2] = (Rectangle){ state.anchor01.x + 48, state.anchor01.y + 224, 64, 24 };// ToggleGroup: ToggleGroup002
    state.layoutRecs[3] = (Rectangle){ state.anchor01.x + 144, state.anchor01.y + 16, 96, 96 };// ColorPicker: AgentColorpicker
    state.layoutRecs[4] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 64, 120, 16 };// SliderBar: SliderBar004
    state.layoutRecs[5] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 96, 120, 16 };// SliderBar: SliderBar005
    state.layoutRecs[6] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 48, 120, 16 };// Label: Label006
    state.layoutRecs[7] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 80, 120, 16 };// Label: Label007
    state.layoutRecs[8] = (Rectangle){ state.anchor01.x + 144, state.anchor01.y + 128, 24, 24 };// CheckBoxEx: CheckBoxEx010
    state.layoutRecs[9] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 128, 120, 16 };// SliderBar: SliderBar010
    state.layoutRecs[10] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 160, 120, 16 };// SliderBar: SliderBar011
    state.layoutRecs[11] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 112, 120, 16 };// Label: Label012
    state.layoutRecs[12] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 144, 120, 16 };// Label: Label013
    state.layoutRecs[13] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 176, 120, 16 };// Label: Label014
    state.layoutRecs[14] = (Rectangle){ state.anchor01.x + 8, state.anchor01.y + 192, 120, 16 };// SliderBar: SliderBar015
    state.layoutRecs[15] = (Rectangle){ state.anchor01.x + 144, state.anchor01.y + 184, 120, 24 };// ValueBOx: ValueBOx015
    state.layoutRecs[16] = (Rectangle){ state.anchor01.x + 144, state.anchor01.y + 168, 120, 16 };// Label: Label016

    // Custom variables initialization

    return state;
}


void GuiControlPanel(GuiControlPanelState *state)
{
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
    
    // Draw controls
    if (state->DropdownBox001EditMode) GuiLock();

    GuiGroupBox(state->layoutRecs[0], GroupBox000Text);
    GuiToggleGroup(state->layoutRecs[2], ToggleGroup002Text, &state->ToggleGroup002Active);
    GuiColorPicker(state->layoutRecs[3], AgentColorpickerText, &state->AgentColorpickerValue);
    GuiSliderBar(state->layoutRecs[4], SliderBar004Text, NULL, &state->SliderBar004Value, 0, 100);
    GuiSliderBar(state->layoutRecs[5], SliderBar005Text, NULL, &state->SliderBar005Value, 0, 100);
    GuiLabel(state->layoutRecs[6], Label006Text);
    GuiLabel(state->layoutRecs[7], Label007Text);
    GuiCheckBox(state->layoutRecs[8], CheckBoxEx010Text, &state->CheckBoxEx010Checked);
    GuiSliderBar(state->layoutRecs[9], SliderBar010Text, NULL, &state->SliderBar010Value, 0, 100);
    GuiSliderBar(state->layoutRecs[10], SliderBar011Text, NULL, &state->SliderBar011Value, 0, 100);
    GuiLabel(state->layoutRecs[11], Label012Text);
    GuiLabel(state->layoutRecs[12], Label013Text);
    GuiLabel(state->layoutRecs[13], Label014Text);
    GuiSliderBar(state->layoutRecs[14], SliderBar015Text, NULL, &state->SliderBar015Value, 0, 100);
    if (GuiValueBox(state->layoutRecs[15], ValueBOx015Text, &state->ValueBOx015Value, 0, 100, state->ValueBOx015EditMode)) state->ValueBOx015EditMode = !state->ValueBOx015EditMode;
    GuiLabel(state->layoutRecs[16], Label016Text);
    if (GuiDropdownBox(state->layoutRecs[1], DropdownBox001Text, &state->DropdownBox001Active, state->DropdownBox001EditMode)) state->DropdownBox001EditMode = !state->DropdownBox001EditMode;
    
    GuiUnlock();
}

#endif // GUI_CONTROL_PANEL_IMPLEMENTATION
