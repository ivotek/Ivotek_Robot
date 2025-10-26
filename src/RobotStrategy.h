#ifndef ROBOT_STRATEGY_H
#define ROBOT_STRATEGY_H

#include <Arduino.h>
#include "../Config/Config.h"

class RobotStrategy
{
public:
    virtual ~RobotStrategy() = default;

    virtual void getVersion() = 0;

    virtual void initialize() = 0;

    virtual void forwards() = 0;
    virtual void forwards(byte speed) = 0;
    virtual void forwards(byte speedSx, byte speedDx) = 0;
    virtual void backwards() = 0;
    virtual void backwards(byte speed) = 0;
    virtual void backwards(byte speedSx, byte speedDx) = 0;
    virtual void turnRight() = 0;
    virtual void turnRight(byte speed) = 0;
    virtual void turnRight(byte speedSx, byte speedDx) = 0;
    virtual void turnLeft() = 0;
    virtual void turnLeft(byte speed) = 0;
    virtual void turnLeft(byte speedSx, byte speedDx) = 0;

    virtual void button(bool direction) = 0;
    virtual void analog(double threshold) = 0;
    virtual int compass() = 0;
    virtual int compass(byte pin) = 0;
    virtual int accelerometer() = 0;
    virtual int accelerometer(byte pin) = 0;

    virtual double ultrasound(byte trigger, byte ultrasound) = 0;
    virtual double ultrasoundSx() = 0;
    virtual double ultrasoundCx() = 0;
    virtual double ultrasoundDx() = 0;
    virtual bool ultrasound(byte trigger, byte echo, double threshold) = 0;
    virtual bool ultrasoundSx(double threshold) = 0;
    virtual bool ultrasoundCx(double threshold) = 0;
    virtual bool ultrasoundDx(double threshold) = 0;

    virtual double pinAnalogRead(int pin) = 0;
    virtual bool pinDigitalRead(byte pin) = 0;
    virtual void pinAnalogWrite(int pin, double value) = 0;
    virtual void pinDigitalWrite(byte pin, bool value) = 0;

    virtual double light(byte pin) = 0;
    virtual double lightSx() = 0;
    virtual double lightCx() = 0;
    virtual double lightDx() = 0;
    virtual bool light(byte pin, double threshold) = 0;
    virtual bool lightSx(double threshold) = 0;
    virtual bool lightCx(double threshold) = 0;
    virtual bool lightDx(double threshold) = 0;
    virtual double batteryStatus() = 0;
    virtual double batteryStatus(byte pin) = 0;
    virtual bool batteryStatus(double threshold) = 0;
    virtual bool batteryStatus(byte pin, double threshold) = 0;

    virtual bool genericSwitch(byte pin) = 0;
    virtual bool genericSwitch(bool invert, byte pin) = 0;
    virtual bool switchSxFront() = 0;
    virtual bool switchDxFront() = 0;
    virtual bool switchSxFront(bool invert) = 0;
    virtual bool switchDxFront(bool invert) = 0;
#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    virtual bool switchSxRear() = 0;
    virtual bool switchDxRear() = 0;
    virtual bool switchSxRear(bool invert) = 0;
    virtual bool switchDxRear(bool invert) = 0;
#endif

    virtual byte temperature() = 0;
    virtual byte temperature(byte pin) = 0;
    virtual bool temperature(byte pin, double threshold) = 0;
    virtual int humidity() = 0;
    virtual int humidity(byte pin) = 0;
    virtual bool humidity(byte pin, double threshold) = 0;

    virtual void pinAnalogOn(byte pin) = 0;
    virtual void pinAnalogOff(byte pin) = 0;
    virtual void pinDigitalOn(byte pin) = 0;
    virtual void pinDigitalOff(byte pin) = 0;

    virtual void ledSoundOn() = 0;
    virtual void ledSoundOff() = 0;
    virtual void ledLightOn() = 0;
    virtual void ledLightOff() = 0;
    virtual void ledGasOn() = 0;
    virtual void ledGasOff() = 0;

    virtual double sound() = 0;
    virtual bool sound(double threshold) = 0;
    virtual bool sound(double threshold, bool invert) = 0;
    virtual bool sound(int pin, double threshold) = 0;
#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE || BOARD == ARDUINO_MEGA
    virtual double sound_1() = 0;
    virtual bool sound_1(double threshold) = 0;
    virtual bool sound_1(double threshold, bool invert) = 0;
    virtual bool sound_1(int pin, double threshold) = 0;
#endif

    virtual double gasAlcool() = 0;
    virtual bool gasAlcool(double threshold) = 0;
    virtual bool gasAlcool(int pin, double threshold) = 0;
    virtual bool gasAlcool(double threshold, bool invert) = 0;
#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE || BOARD == ARDUINO_MEGA
    virtual double gasAlcool_1() = 0;
    virtual bool gasAlcool_1(double threshold) = 0;
    virtual bool gasAlcool_1(int pin, double threshold) = 0;
    virtual bool gasAlcool_1(double threshold, bool invert) = 0;
#endif

    virtual void stop() = 0;

};

#endif
