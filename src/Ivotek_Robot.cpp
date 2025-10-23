#include "Ivotek_Robot.h"
#include "ExplorerRobot.h"
#include "../Config/RobotInfo.h"
//#include "Robot/PoorV2Robot.h"
//#include "Robot/SnailRobot.h"
//#include "Robot/DefaultRobot.h"

void Ivotek_Robot::setStrategy(RobotStrategy* strategy)
{
    robot = strategy;
    robot->initialize();
}

void Ivotek_Robot::initialization(String name)
{
    name.toUpperCase();
    RobotInfo::setRobotName(name);

    if (RobotInfo::getRobotName() == "EXPLORER") setStrategy(new ExplorerRobot());
    //else if (robotName == "POORV2") setStrategy(new PoorV2Robot());
    //else if (robotName == "SNAIL") setStrategy(new SnailRobot());
    //else setStrategy(new DefaultRobot());
}

void Ivotek_Robot::forwards() { if (robot) robot->forwards(); }
void Ivotek_Robot::forwards(byte speed) { if (robot) robot->forwards(speed); }
void Ivotek_Robot::forwards(byte speedSx, byte speedDx) { if (robot) robot->forwards(speedSx, speedDx); }
void Ivotek_Robot::backwards() { if (robot) robot->backwards(); }
void Ivotek_Robot::backwards(byte speed) { if (robot) robot->backwards(speed); }
void Ivotek_Robot::backwards(byte speedSx, byte speedDx) { if (robot) robot->backwards(speedSx, speedDx); }
void Ivotek_Robot::turnRight() { if (robot) robot->turnRight(); }
void Ivotek_Robot::turnRight(byte speed) { if (robot) robot->turnRight(speed); }
void Ivotek_Robot::turnRight(byte speedSx, byte speedDx) { if (robot) robot->turnRight(speedSx, speedDx); }
void Ivotek_Robot::turnLeft() { if (robot) robot->turnLeft(); }
void Ivotek_Robot::turnLeft(byte speed) { if (robot) robot->turnLeft(speed); }
void Ivotek_Robot::turnLeft(byte speedSx, byte speedDx) { if (robot) robot->turnLeft(speedSx, speedDx); }

void Ivotek_Robot::button(bool direction) { if (robot) robot->button(direction); }
void Ivotek_Robot::analog(double threshold) { if (robot) robot->analog(threshold); }
int Ivotek_Robot::compass() { if (robot) robot->compass(); }
int Ivotek_Robot::compass(byte pin) { if (robot) robot->compass(pin); }
int Ivotek_Robot::accelerometer() { if (robot) robot->accelerometer(); }
int Ivotek_Robot::accelerometer(byte pin) { if (robot) robot->accelerometer(pin); }

double Ivotek_Robot::ultrasound(byte trigger, byte ultrasound) { if (robot) robot->ultrasound(trigger,ultrasound); }
double Ivotek_Robot::ultrasoundSx() { if (robot) robot->ultrasoundSx(); }

void Ivotek_Robot::stop() { if (robot) robot->stop(); }
void Ivotek_Robot::getVersion() { if (robot) robot->getVersion(); }



