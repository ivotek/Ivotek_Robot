#ifndef EXPLORER_ROBOT_H
#define EXPLORER_ROBOT_H

#include "RobotStrategy.h"
#include "../Config/RobotPins.h"

class ExplorerRobot : public RobotStrategy
{
private:
    ArduinoPins arduinoPins;
    STNucleoPins stNucleoPins;

public:
    ExplorerRobot(); // Costruttore

    void initialize() override;

    void forwards() override;
    void forwards(byte speed) override;
    void forwards(byte speedSx, byte speedDx) override;
    void backwards() override;
    void backwards(byte speed) override;
    void backwards(byte speedSx, byte speedDx) override;
    void turnRight() override;
    void turnRight(byte speed) override;
    void turnRight(byte speedSx, byte speedDx) override;
    void turnLeft() override;
    void turnLeft(byte speed) override;
    void turnLeft(byte speedSx, byte speedDx) override;
    void stop() override;

    void button(bool direction) override;
    void analog(double threshold) override;
    int compass() override;
    int compass(byte pin) override;
    int accelerometer() override;
    int accelerometer(byte pin) override;

    double ultrasound(byte trigger, byte ultrasound) override;
    double ultrasoundSx() override;
    double ultrasoundCx() override;
    double ultrasoundDx() override;
    bool ultrasound(byte trigger, byte echo, double threshold) override;
    bool ultrasoundSx(double threshold) override;
    bool ultrasoundCx(double threshold) override;
    bool ultrasoundDx(double threshold) override;

    double pinAnalogRead(int pin) override;
    bool pinDigitalRead(byte pin) override;
    void pinAnalogWrite(int pin, double value) override;
    void pinDigitalWrite(byte pin, bool value) override;

    double light(byte pin) override;
    double lightSx() override;
    double lightCx() override;
    double lightDx() override;
    bool light(byte pin, double threshold) override;
    bool lightSx(double threshold) override;
    bool lightCx(double threshold) override;
    bool lightDx(double threshold) override;

    double batteryStatus() override;
    double batteryStatus(byte pin) override;
    bool batteryStatus(double threshold) override;
    bool batteryStatus(byte pin, double threshold) override;

    bool genericSwitch(byte pin) override;
    bool genericSwitch(bool invert, byte pin) override;
    bool switchSxFront() override;
    bool switchDxFront() override;
    bool switchSxFront(bool invert) override;
    bool switchDxFront(bool invert) override;
#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    bool switchSxRear() override;
    bool switchDxRear() override;
    bool switchSxRear(bool invert) override;
    bool switchDxRear(bool invert) override;
#endif

    byte temperature() override;
    byte temperature(byte pin) override;
    bool temperature(byte pin, double threshold) override;
    int humidity() override;
    int humidity(byte pin) override;
    bool humidity(byte pin, double threshold) override;

    void pinAnalogOn(byte pin) override;
    void pinAnalogOff(byte pin) override;
    void pinDigitalOn(byte pin) override;
    void pinDigitalOff(byte pin) override;

    void ledSoundOn() override;
    void ledSoundOff() override;
    void ledLightOn() override;
    void ledLightOff() override;
    void ledGasOn() override;
    void ledGasOff() override;

    double sound() override;
    bool sound(double threshold) override;
    bool sound(double threshold, bool invert) override;
    bool sound(int pin, double threshold) override;

#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    double sound_1() override;
    bool sound_1(double threshold) override;
    bool sound_1(double threshold, bool invert) override;
    bool sound_1(int pin, double threshold) override;
#endif

    double gasAlcool() override;
    bool gasAlcool(double threshold) override;
    bool gasAlcool(int pin, double threshold) override;
    bool gasAlcool(double threshold, bool invert) override;
#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    double gasAlcool_1();
    bool gasAlcool_1(double threshold);
    bool gasAlcool_1(int pin, double threshold);
    bool gasAlcool_1(double threshold, bool invert);
#endif

    void getVersion() override;
};
#endif
