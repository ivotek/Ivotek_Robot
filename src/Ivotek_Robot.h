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
    void turnLeft();
    void turnLeft(byte speed);
    void turnLeft(byte speedSx, byte speedDx);

    void stop();
};

#endif
