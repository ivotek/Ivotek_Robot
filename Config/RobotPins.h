// RobotPins.h
#ifndef ROBOT_PINS_H
#define ROBOT_PINS_H

#include <Arduino.h>

struct RobotPins {
    byte arduinoDigit0;
    byte arduinoDigit1;
    byte arduinoDigit2;
    byte arduinoDigit3;
    byte arduinoDigit4;
    byte arduinoDigit5;
    byte arduinoDigit6;
    byte arduinoDigit7;
    byte arduinoDigit8;
    byte arduinoDigit9;
    byte arduinoDigit10;
    byte arduinoDigit11;
    byte arduinoDigit12;
    byte arduinoDigit13;
    byte arduinoAnalog0;
    byte arduinoAnalog1;
    byte arduinoAnalog2;
    byte arduinoAnalog3;
    byte arduinoAnalog4;
    byte arduinoAnalog5;
    int arduinoAnalog6 = A6;
    int arduinoAnalog7 = A7;
    //int arduinoAnalog6 = PC2;
    //int arduinoAnalog7 = PC3;
    int nucleoSwitchSxRear = PC15;
    int nucleoSwitchDxRear = PC14;
    
};

#endif

