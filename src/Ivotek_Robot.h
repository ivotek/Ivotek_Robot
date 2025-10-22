#ifndef IVOTEK_ROBOT_H
#define IVOTEK_ROBOT_H

#include <Arduino.h>
#include "RobotStrategy.h"

class Ivotek_Robot {
private:
    RobotStrategy* robot = nullptr;
    
public:
    Ivotek_Robot() = default;
  
    void initialization(String name);
    void setStrategy(RobotStrategy* strategy);
    void getVersion();
    void forwards();
    void backwards();
    void turnLeft();
    void turnRight();
    void stop();
};

#endif
