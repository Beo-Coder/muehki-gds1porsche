
// Copyright (c) 2023. Leonhard Baschang


#ifndef PORSCHE_MUEK_INPUT_AXIS_H
#define PORSCHE_MUEK_INPUT_AXIS_H

class MCP3204_MCP3208;

#define BASE_MAX 0.99
#define BASE_MIN (-0.99)

#define BASE_STEP_SIZE 0.01
#define BASE_DISPLAY_RESOLUTION 2

#include "LCDInput/Menu.h"

class Navigator;





class Axis {


    String name;
    uint16_t currentRawValue;
    uint16_t previousRawValue;

    MCP3204_MCP3208 *adc;

    uint8_t index;

    uint16_t calibrationData[3]{};
    bool calibrateCenter = false;
    uint16_t digitalCalibrationData[2]{};
    double base[2]{};

    uint8_t mode = 0;
    uint8_t digitalIndex{};
    uint8_t adcIndexChannel[8] = {3,2,1,0,7,6,5,4};



    long linearCalculation(uint16_t value);
    double expCalculation(double value);
    int digitalCalculation(double value);





public:

    Menu *settingsMenu{};
    uint16_t readSensor() const;



    Axis(uint8_t index, MCP3204_MCP3208 *adc);

    uint8_t getIndex() const;

    void setBase(double pBase1, double pBase2);
    double * getBase();


    void setCalibrationData(const uint16_t pCalibrationData[3]);
    uint16_t * getCalibrationData();

    void setDigitalCalibrationData(const uint16_t pDigitalCalibrationData[2]);
    uint16_t * getDigitalCalibrationData();

    void setCalibrateCenter(bool pCalibrateCenter);
    bool getCalibrateCenter() const;

    void setMode(uint8_t pMode);
    uint8_t getMode() const;

    void setDigitalIndex(uint8_t pIndex);
    uint8_t getDigitalIndex() const;


    int32_t getValue();
    int getDigitalValue();

    bool valueChanged();


    void initSettingsMenu(Navigator *navigator);
    static void axisEntryAction(Navigator *navigator, uint8_t index);



};


#endif //PORSCHE_MUEK_INPUT_AXIS_H
