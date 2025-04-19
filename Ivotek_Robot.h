//Includiamo la libreria se non è già stata inclusa
//da un altra libreria
#ifndef Ivotek_Robot_H
#define Ivotek_Robot_H

#include "Arduino.h"

class Ivotek_Robot
{
private:
    String robotName = "default";
    String boardName = "default";
    String VERSION = "1.0.0";
    byte digit0 = 0;
    byte digit1 = 1;
    byte digit2 = 2;
    byte digit3 = 3;
    byte digit4 = 4;
    byte digit5 = 5;
    byte digit6 = 6;
    byte digit7 = 7;
    byte digit8 = 8;
    byte digit9 = 9;
    byte digit10 = 10;
    byte digit11 = 11;
    byte digit12 = 12;
    byte digit13 = 13;
    byte digit14 = 14;
    byte digit15 = 15;
    byte analog0 = A0;
    byte analog1 = A1;
    byte analog2 = A2;
    byte analog3 = A3;
    byte analog4 = A4;
    byte analog5 = A5;

public:
    void initialization(String name = "default", String board = "default");

    void forwards();
    void backwards();
    void turnRight();
    void turnLeft();
    void stop();

    void forwards(byte speed);
    void backwards(byte speed);
    void turnRight(byte speed);
    void turnLeft(byte speed);
    void turnRight(byte speedSx, byte speedDx);
    void turnLeft(byte speedSx, byte speedDx);
    void forwards(byte speedSx, byte speedDx);
    void backwards(byte speedSx, byte speedDx);

    void button(bool direction);
    void analog(double threshold);
    void pinHigh(byte pin);
    void pinDown(byte pin);
    void ledSoundOn();
    void ledSoundOff();
    void ledLightOn();
    void ledLightOff();
    void ledGasOn();
    void ledGasOff();

    int compass();
    int compass(byte pin);
    int accelerometer();
    int accelerometer(byte pin);


    double ultrasound(byte trigger, byte ultrasound);
    bool ultrasound (byte trigger, byte ultrasound, double threshold);
    double ultrasoundSx();
    bool ultrasoundSx(double threshold);
    double ultrasoundDx();
    bool ultrasoundDx(double threshold);
    double ultrasoundCx();
    bool ultrasoundCx(double threshold);


    double lightSx();
    double lightCx();
    double lightDx();
    double light(byte pin);
    bool light(byte pin, double threshold);
    bool lightSx(double threshold);
    bool lightCx(double threshold);
    bool lightDx(double threshold);

    double batteryStatus();
    double batteryStatus(byte pin);
    bool batteryStatus(double threshold);
    bool batteryStatus(byte pin, double threshold);

    byte temperature();
    byte temperature(byte pin);
    bool temperature(byte pin, double threshold);
    int humidity();
    int humidity(byte pin);
    bool humidity(byte pin, double threshold);

    bool switchSxFront();
    bool switchDxFront();
    bool switchSxFront(bool invert);
    bool switchDxFront(bool invert);
    bool switchSxRear();
    bool switchDxRear();
    bool switchSxRear(bool invert);
    bool switchDxRear(bool invert);
    bool genericSwitch(byte pin);
    bool genericSwitch(bool invert, byte pin);

    void getVersion();


};

#endif // Ivotek_Robot_H
