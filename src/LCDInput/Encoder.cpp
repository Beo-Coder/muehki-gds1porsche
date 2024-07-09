// Copyright (c) 2023. Leonhard Baschang

#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(uint8_t clkPin, uint8_t dtPin, uint8_t buttonPin, void (*isr)()) {
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);
    pinMode(buttonPin, INPUT);
    this->buttonPin = buttonPin;

    attachInterrupt(digitalPinToInterrupt(clkPin), isr, FALLING);

    lastButtonPress = 0;


}

void Encoder::setEncoderFlag(int8_t direction) {
    flag = direction;
}

void Encoder::resetEncoderFlag() {
    flag = 0;
}

void Encoder::setButtonFlag() {
    if(millis()-lastButtonPress > 50){
        lastButtonPress = millis();
        buttonFlag = true;
    }

}

bool Encoder::readButton() const {
    return digitalRead(buttonPin);
}

void Encoder::checkButton() {
    uint8_t buttonState = readButton();
    if (buttonState && !previousButtonState) {
        previousButtonState = true;
        setButtonFlag();
    } else if (!buttonState && previousButtonState) {
        previousButtonState = false;
    }

}
