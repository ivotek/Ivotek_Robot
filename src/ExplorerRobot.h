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
    void turnLeft(byte speedSx,byte speedDx) override;
    void stop() override;

    void button(bool direction) override;
    void analog(double threshold) override;
    int compass() override;
    int compass(byte pin) override;
    int accelerometer() override;
    int accelerometer(byte pin) override;

    double ultrasound(byte trigger, byte ultrasound) override;
    double ultrasoundSx() override;

    void getVersion() override;
};

#endif

