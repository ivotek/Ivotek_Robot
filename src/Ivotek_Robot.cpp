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
void Ivotek_Robot::stop() { if (robot) robot->stop(); }

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

bool Ivotek_Robot::genericSwitch(byte pin) { if (robot) robot->genericSwitch(pin); };
bool Ivotek_Robot::genericSwitch(bool invert, byte pin) { if (robot) robot->genericSwitch(invert, pin); };
bool Ivotek_Robot::switchSxFront() { if (robot) robot->switchSxFront(); };
bool Ivotek_Robot::switchDxFront() { if (robot) robot->switchDxFront(); };
bool Ivotek_Robot::switchSxFront(bool invert) { if (robot) robot->switchSxFront(invert); };
bool Ivotek_Robot::switchDxFront(bool invert) { if (robot) robot->switchDxFront(invert); };
#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    bool Ivotek_Robot::switchSxRear() { if (robot) robot->switchSxRear(); };
    bool Ivotek_Robot::switchDxRear() { if (robot) robot->switchDxRear(); };
    bool Ivotek_Robot::switchSxRear(bool invert) { if (robot) robot->switchSxRear(); };
    bool Ivotek_Robot::switchDxRear(bool invert) { if (robot) robot->switchDxRear(); };
#endif

byte Ivotek_Robot::temperature()  { if (robot) robot->temperature(); };
byte Ivotek_Robot::temperature(byte pin)  { if (robot) robot->temperature(pin); };
bool Ivotek_Robot::temperature(byte pin, double threshold)  { if (robot) robot->temperature(pin, threshold); };
int Ivotek_Robot::humidity()  { if (robot) robot->humidity(); };
int Ivotek_Robot::humidity(byte pin)  { if (robot) robot->humidity(pin); };
bool Ivotek_Robot::humidity(byte pin, double threshold)  { if (robot) robot->humidity(pin, threshold); };

void Ivotek_Robot::pinAnalogOn(byte pin) { if (robot) robot->pinAnalogOn(pin); };
void Ivotek_Robot::pinAnalogOff(byte pin) { if (robot) robot->pinAnalogOff(pin); };
void Ivotek_Robot::pinDigitalOn(byte pin)  { if (robot) robot->pinDigitalOn(pin); };
void Ivotek_Robot::pinDigitalOff(byte pin)  { if (robot) robot->pinDigitalOff(pin); };


void Ivotek_Robot::ledSoundOn() { if (robot) robot->ledSoundOn(); };
void Ivotek_Robot::ledSoundOff() { if (robot) robot->ledSoundOff(); };
void Ivotek_Robot::ledLightOn() { if (robot) robot->ledLightOn(); }; 
void Ivotek_Robot::ledLightOff() { if (robot) robot->ledLightOff(); };
void Ivotek_Robot::ledGasOn() { if (robot) robot->ledGasOn(); };
void Ivotek_Robot::ledGasOff() { if (robot) robot->ledGasOff(); };

double Ivotek_Robot::sound() { if (robot) robot->sound(); };
bool Ivotek_Robot:: sound(double threshold) { if (robot) robot->sound(threshold); };
bool Ivotek_Robot:: sound(double threshold, bool invert) { if (robot) robot->sound(threshold, invert); };
bool Ivotek_Robot:: sound(int pin, double threshold) { if (robot) robot->sound(pin, threshold); };
#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    double Ivotek_Robot::sound_1() { if (robot) robot->sound_1(); };
    bool Ivotek_Robot::sound_1(double threshold) { if (robot) robot->sound_1(threshold); };
    bool Ivotek_Robot::sound_1(double threshold, bool invert) { if (robot) robot->sound_1(threshold, invert); };
    bool Ivotek_Robot::sound_1(int pin, double threshold) { if (robot) robot->sound_1(pin, threshold); };
#endif

double Ivotek_Robot::gasAlcool() { if (robot) robot->gasAlcool(); };
bool Ivotek_Robot::gasAlcool(double threshold) { if (robot) robot->gasAlcool(threshold); };
bool Ivotek_Robot::gasAlcool(int pin, double threshold) { if (robot) robot->gasAlcool(pin, threshold); };
bool Ivotek_Robot::gasAlcool(double threshold, bool invert) { if (robot) robot->gasAlcool(threshold, invert); };
#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    double Ivotek_Robot::gasAlcool_1(){ if (robot) robot->gasAlcool_1(); };
    bool Ivotek_Robot::gasAlcool_1(double threshold){ if (robot) robot->gasAlcool_1(threshold); };
    bool Ivotek_Robot::gasAlcool_1(int pin, double threshold){ if (robot) robot->gasAlcool_1(pin, threshold); };
    bool Ivotek_Robot::gasAlcool_1(double threshold, bool invert){ if (robot) robot->gasAlcool_1(threshold, invert); };
#endif


void Ivotek_Robot::getVersion() { if (robot) robot->getVersion(); }



