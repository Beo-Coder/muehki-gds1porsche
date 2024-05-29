
// Copyright (c) 2023. Leonhard Baschang


#ifndef PORSCHE_MUEK_INPUT_BUTTON_H
#define PORSCHE_MUEK_INPUT_BUTTON_H

#include "LCDInput/Menu.h"


class Button {

    bool toggleMode = false;
    bool normalOpen = true;

    bool currentState{};
    bool toggleState = false;
    unsigned long lastPressed = 0;

    uint8_t index;

public:

    explicit Button(uint8_t pIndex);


    bool getState() const;
    bool stateChanged(uint8_t newState);

    void setToggleMode(bool pToggleMode);
    bool getToggleMode() const;

    void setNormalOpen(bool pNormalOpen);
    bool getNormalOpen() const;



    Menu *settingsMenu{};
    void initSettingsMenu(Navigator *navigator);
    static void buttonEntryAction(Navigator *navigator, uint8_t index);



};


#endif //PORSCHE_MUEK_INPUT_BUTTON_H
