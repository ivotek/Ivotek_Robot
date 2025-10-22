#include "Ivotek_Robot.h"
#include "ExplorerRobot.h"
#include "../Config/RobotInfo.h"
//#include "Robot/PoorV2Robot.h"
//#include "Robot/SnailRobot.h"
//#include "Robot/DefaultRobot.h"

void Ivotek_Robot::setStrategy(RobotStrategy* strategy) {
    robot = strategy;
    robot->initialize();
}

void Ivotek_Robot::initialization(String name) {
    name.toUpperCase();
    RobotInfo::setRobotName(name);

    if (RobotInfo::getRobotName() == "EXPLORER") setStrategy(new ExplorerRobot());
    //else if (robotName == "POORV2") setStrategy(new PoorV2Robot());
    //else if (robotName == "SNAIL") setStrategy(new SnailRobot());
    //else setStrategy(new DefaultRobot());
}

void Ivotek_Robot::forwards()  { if (robot) robot->forwards(); }
void Ivotek_Robot::backwards() { if (robot) robot->backwards(); }
void Ivotek_Robot::turnLeft()  { if (robot) robot->turnLeft(); }
void Ivotek_Robot::turnRight() { if (robot) robot->turnRight(); }
void Ivotek_Robot::stop()      { if (robot) robot->stop(); }
void Ivotek_Robot::getVersion() { if (robot) robot->getVersion(); }


