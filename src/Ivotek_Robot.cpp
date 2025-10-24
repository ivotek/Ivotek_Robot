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
double Ivotek_Robot::ultrasoundCx() { if (robot) robot->ultrasoundCx(); }
double Ivotek_Robot::ultrasoundDx() { if (robot) robot->ultrasoundDx(); }
bool Ivotek_Robot::ultrasound(byte trigger, byte echo, double threshold) { if (robot) robot->ultrasound(trigger,echo, threshold); }
bool Ivotek_Robot::ultrasoundSx(double threshold) { if (robot) robot->ultrasoundSx(threshold); }
bool Ivotek_Robot::ultrasoundCx(double threshold) { if (robot) robot->ultrasoundCx(threshold); }
bool Ivotek_Robot::ultrasoundDx(double threshold) { if (robot) robot->ultrasoundDx(threshold); }

double Ivotek_Robot::pinAnalogRead(int pin) { if (robot) robot->pinAnalogRead(pin); }
bool Ivotek_Robot::pinDigitalRead(byte pin) { if (robot) robot->pinDigitalRead(pin); }
void Ivotek_Robot::pinAnalogWrite(int pin, double value) { if (robot) robot->pinAnalogWrite(pin, value); }
void Ivotek_Robot::pinDigitalWrite(byte pin, bool value) { if (robot) robot->pinDigitalWrite(pin, value); }

double Ivotek_Robot::light(byte pin) { if (robot) robot->light(pin); }
double Ivotek_Robot::lightSx() { if (robot) robot->lightSx(); }
double Ivotek_Robot::lightCx() { if (robot) robot->lightCx(); }
double Ivotek_Robot::lightDx() { if (robot) robot->lightDx(); }
bool Ivotek_Robot::light(byte pin, double threshold) { if (robot) robot->light(pin, threshold); }
bool Ivotek_Robot::lightSx(double threshold) { if (robot) robot->lightSx(threshold); }
bool Ivotek_Robot::lightCx(double threshold) { if (robot) robot->lightCx(threshold); }
bool Ivotek_Robot::lightDx(double threshold) { if (robot) robot->lightDx(threshold); }

double Ivotek_Robot::batteryStatus() { if (robot) robot->batteryStatus(); };
double Ivotek_Robot::batteryStatus(byte pin) { if (robot) robot->batteryStatus(pin); };
bool Ivotek_Robot::batteryStatus(double threshold) { if (robot) robot->batteryStatus(threshold); };
bool Ivotek_Robot::batteryStatus(byte pin, double threshold) { if (robot) robot->batteryStatus(pin, threshold); };

void Ivotek_Robot::stop() { if (robot) robot->stop(); }
void Ivotek_Robot::getVersion() { if (robot) robot->getVersion(); }



