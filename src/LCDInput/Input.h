// Copyright (c) 2023. Leonhard Baschang

#ifndef GDS1PORSCHEMUEHK_INPUT_H
#define GDS1PORSCHEMUEHK_INPUT_H

#include "Input/Axis.h"
#include "Input/Button.h"


class Navigator;

class Input {

    Navigator *navigator;

    double currentValue{};
    double previousValue{};
    double *valuePointer{};
    double maxValue{};
    double minValue{};
    double stepSize{};
    uint8_t displayResolution{};

    uint8_t *selectValuePointer{};
    uint8_t selectIndex{};
    uint8_t previousSelectIndex{};
    String selectValues[10];
    uint8_t selectValuesSize{};
    uint8_t scrollOffset = 0;





    void displayValue();

    void displaySelectInput();
    void displaySelectCursor();
    void displaySplashScreen(String *values);
    void waitUntilButtonPressed();

public:


    explicit Input(Navigator *navigator);



    void valueInput(const String &header, double *value, double startValue, double pMaxValue, double pMinValue,
                    double pStepSize, uint8_t pDisplayResolution);

    void changeValueInput(int8_t direction);


    void setValue();


    void selectInput(const String &header, uint8_t *value, uint8_t startIndex, String *values, uint8_t valuesSize);



    void changeSelectInput(int8_t direction);


    void setSelect();

    void setSplashScreen(String *values);

    void returnToMenu();





    void axisCalibration(Axis *axis);


    void axisSetBase(Axis *axis);

    void axisSetMode(Axis *axis);

    void axisCalibrationDigital(Axis *axis);

    void generalSetAxisCount();
    void generalSetButtonCount();
    void generalSetMode();
    void generalSetPreset();
    void generalSavePreset();

    void reinitPrompt();

    void showWaitScreen(String *values);
    void endWaitScreen();

    void showEEPROMWaitScreen();

    void resetPresetPrompt();
    void factoryResetPrompt();

    void buttonMode(Button *button);
    void buttonType(Button *button);
};


#endif //GDS1PORSCHEMUEHK_INPUT_H
