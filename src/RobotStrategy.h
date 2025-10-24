#ifndef ROBOT_STRATEGY_H
#define ROBOT_STRATEGY_H

#include <Arduino.h>

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

    virtual void stop() = 0;

    /*
        virtual void turnRight(byte speed);
        virtual void turnLeft(byte speed);
        virtual void turnRight(byte speedSx, byte speedDx);
        virtual void turnLeft(byte speedSx, byte speedDx);
        virtual void forwards(byte speedSx, byte speedDx);
        virtual void backwards(byte speedSx, byte speedDx);

        //TODO da sostituire o sistemare
        virtual void button(bool direction);
        virtual void analog(double threshold);
        virtual void ledSoundOn();
        virtual void ledSoundOff();
        virtual void ledLightOn();
        virtual void ledLightOff();
        virtual void ledGasOn();
        virtual void ledGasOff();
        virtual void pinAnalogOn(byte pin);
        virtual void pinAnalogOff(byte pin);
        virtual void pinDigitalOn(byte pin);
        virtual void pinDigitalOff(byte pin);
        virtual double pinAnalogRead(int pin);
        virtual bool pinDigitalRead(byte pin);
        virtual void pinAnalogWrite(byte pin, double value);
        virtual void pinDigitalWrite(byte pin, bool value);


        virtual int compass();
        virtual int compass(byte pin);
        virtual int accelerometer();
        virtual int accelerometer(byte pin);


        virtual double ultrasound(byte trigger, byte ultrasound);
        virtual bool ultrasound (byte trigger, byte ultrasound, double threshold);
        virtual double ultrasoundSx();
        virtual bool ultrasoundSx(double threshold);
        virtual double ultrasoundDx();
        virtual bool ultrasoundDx(double threshold);
        virtual double ultrasoundCx();
        virtual bool ultrasoundCx(double threshold);


        virtual double lightSx();
        virtual double lightCx();
        virtual double lightDx();
        virtual double light(byte pin);
        virtual bool light(byte pin, double threshold);
        virtual bool lightSx(double threshold);
        virtual bool lightCx(double threshold);
        virtual bool lightDx(double threshold);
        virtual double sound();
        virtual bool sound(double threshold);
        virtual bool sound(double threshold, bool invert);
        virtual bool sound(int pin, double threshold);
        virtual double sound_1();
        virtual bool sound_1(double threshold);
        virtual bool sound_1(double threshold, bool invert);
        virtual bool sound_1(int pin, double threshold);
        virtual double gasAlcool();
        virtual bool gasAlcool(double threshold);
        virtual bool gasAlcool(double threshold, bool invert);
        virtual bool gasAlcool(int pin, double threshold);
        virtual double gasAlcool_1();
        virtual bool gasAlcool_1(double threshold);
        virtual bool gasAlcool_1(double threshold, bool invert);
        virtual bool gasAlcool_1(int pin, double threshold);

        virtual double batteryStatus();
        virtual double batteryStatus(byte pin);
        virtual bool batteryStatus(double threshold);
        virtual bool batteryStatus(byte pin, double threshold);

        virtual byte temperature();
        virtual byte temperature(byte pin);
        virtual bool temperature(byte pin, double threshold);
        virtual int humidity();
        virtual int humidity(byte pin);
        virtual bool humidity(byte pin, double threshold);

        virtual bool switchSxFront();
        virtual bool switchDxFront();
        virtual bool switchSxFront(bool invert);
        virtual bool switchDxFront(bool invert);
        virtual bool switchSxRear();
        virtual bool switchDxRear();
        virtual bool switchSxRear(bool invert);
        virtual bool switchDxRear(bool invert);
        virtual bool genericSwitch(byte pin);
        virtual bool genericSwitch(bool invert, byte pin);
    */

};

#endif
