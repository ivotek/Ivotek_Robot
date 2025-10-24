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

    byte temperature() override;
    byte temperature(byte pin) override;
    bool temperature(byte pin, double threshold) override;
    int humidity() override;
    int humidity(byte pin) override;
    bool humidity(byte pin, double threshold) override;

    void getVersion() override;
};
#endif
