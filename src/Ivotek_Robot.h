#ifndef IVOTEK_ROBOT_H
#define IVOTEK_ROBOT_H

#include <Arduino.h>
#include "RobotStrategy.h"

class Ivotek_Robot
{
private:
    RobotStrategy* robot = nullptr;

public:
    Ivotek_Robot() = default;

    void initialization(String name);
    void setStrategy(RobotStrategy* strategy);
    void getVersion();

    void forwards();
    void forwards(byte speed);
    void forwards(byte speedSx, byte speedDx);
    void backwards();
    void backwards(byte speed);
    void backwards(byte speedSx, byte speedDx);
    void turnRight();
    void turnRight(byte speed);
    void turnRight(byte speedSx, byte speedDx);
    void turnLeft();
    void turnLeft(byte speed);
    void turnLeft(byte speedSx, byte speedDx);
    void stop();

    void button(bool direction);
    void analog(double threshold);

    int compass();
    int compass(byte pin);
    int accelerometer();
    int accelerometer(byte pin);

    double ultrasound(byte trigger, byte ultrasound);
    double ultrasoundSx();
    double ultrasoundCx();
    double ultrasoundDx();
    bool ultrasound(byte trigger, byte echo, double threshold);
    bool ultrasoundSx(double threshold);
    bool ultrasoundCx(double threshold);
    bool ultrasoundDx(double threshold);

    double pinAnalogRead(int pin);
    bool pinDigitalRead(byte pin);
    void pinAnalogWrite(int pin, double value);
    void pinDigitalWrite(byte pin, bool value);

    double light(byte pin);
    double lightSx();
    double lightCx();
    double lightDx();
    bool light(byte pin, double threshold);
    bool lightSx(double threshold);
    bool lightCx(double threshold);
    bool lightDx(double threshold);

    double batteryStatus();
    double batteryStatus(byte pin);
    bool batteryStatus(double threshold);
    bool batteryStatus(byte pin, double threshold);

    bool genericSwitch(byte pin);
    bool genericSwitch(bool invert, byte pin);
    bool switchSxFront();
    bool switchDxFront();
    bool switchSxFront(bool invert);
    bool switchDxFront(bool invert);

    byte temperature();
    byte temperature(byte pin) ;
    bool temperature(byte pin, double threshold);
    int humidity();
    int humidity(byte pin);
    bool humidity(byte pin, double threshold);

    void pinAnalogOn(byte pin);
    void pinAnalogOff(byte pin);
    void pinDigitalOn(byte pin);
    void pinDigitalOff(byte pin);

    void ledSoundOn();
    void ledSoundOff();
    void ledLightOn();
    void ledLightOff();
    void ledGasOn();
    void ledGasOff();

    double sound();
    bool sound(double threshold);
    bool sound(double threshold, bool invert);
    bool sound(int pin, double threshold);

    double gasAlcool();
    bool gasAlcool(double threshold);
    bool gasAlcool(int pin, double threshold);
    bool gasAlcool(double threshold, bool invert);


};

#endif
