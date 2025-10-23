#include <Arduino.h>
#include "ExplorerRobot.h"
#include "../Config/RobotInfo.h"

ExplorerRobot::ExplorerRobot()
{
    // Inizializzazione dei pin
#if BOARD == ARDUINO_UNO || BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8
    arduinoPins.d5 = 5;
    arduinoPins.d6 = 6;
    arduinoPins.d9 = 9;
    arduinoPins.d10 = 10;
#endif

#if BOARD == ARDUINO_NANO
    arduinoPins.a6 = A6;
    arduinoPins.a7 = A7;
#endif

#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    stNucleoPins.pc2 = PC2;
    stNucleoPins.pc3 = PC3;
    stNucleoPins.pc15 = PC15;
    stNucleoPins.pc14 = PC14;
#endif

}

void ExplorerRobot::initialize()
{
    pinMode(arduinoPins.d5, OUTPUT);
    pinMode(arduinoPins.d6, OUTPUT);
    pinMode(arduinoPins.d9, OUTPUT);
    pinMode(arduinoPins.d10, OUTPUT);
}

void ExplorerRobot::forwards()
{
    analogWrite(arduinoPins.d5, 255);
    analogWrite(arduinoPins.d6, 0);
    analogWrite(arduinoPins.d9, 255);
    analogWrite(arduinoPins.d10, 0);
}

void ExplorerRobot::forwards(byte speed)
{
    analogWrite(arduinoPins.d5,speed);
    analogWrite(arduinoPins.d6,0);
    analogWrite(arduinoPins.d9,speed);
    analogWrite(arduinoPins.d10,0);
}

void ExplorerRobot::forwards(byte speedSx, byte speedDx)
{
    analogWrite(arduinoPins.d5,speedSx);
    analogWrite(arduinoPins.d6,0);
    analogWrite(arduinoPins.d9,speedDx);
    analogWrite(arduinoPins.d10,0);

}

void ExplorerRobot::backwards()
{
    analogWrite(arduinoPins.d5, 0);
    analogWrite(arduinoPins.d6, 255);
    analogWrite(arduinoPins.d9, 0);
    analogWrite(arduinoPins.d10, 255);
}


void ExplorerRobot::backwards(byte speed)
{
    analogWrite(arduinoPins.d5,0);
    analogWrite(arduinoPins.d6,speed);
    analogWrite(arduinoPins.d9,0);
    analogWrite(arduinoPins.d10,speed);
}

void ExplorerRobot::backwards(byte speedSx, byte speedDx)
{
    analogWrite(arduinoPins.d5,0);
    analogWrite(arduinoPins.d6,speedSx);
    analogWrite(arduinoPins.d9,0);
    analogWrite(arduinoPins.d10,speedDx);
}

void ExplorerRobot::turnRight()
{
    analogWrite(arduinoPins.d5, 255);
    analogWrite(arduinoPins.d6, 0);
    analogWrite(arduinoPins.d9, 0);
    analogWrite(arduinoPins.d10, 255);
}

void ExplorerRobot::turnRight(byte speed)
{
    analogWrite(arduinoPins.d5,speed);
    analogWrite(arduinoPins.d6,0);
    analogWrite(arduinoPins.d9,0);
    analogWrite(arduinoPins.d10,speed);
}

void ExplorerRobot::turnRight(byte speedSx, byte speedDx)
{
    analogWrite(arduinoPins.d5,speedSx);
    analogWrite(arduinoPins.d6,0);
    analogWrite(arduinoPins.d9,0);
    analogWrite(arduinoPins.d10,speedDx);
}

void ExplorerRobot::turnLeft()
{
    analogWrite(arduinoPins.d5, 0);
    analogWrite(arduinoPins.d6, 255);
    analogWrite(arduinoPins.d9, 255);
    analogWrite(arduinoPins.d10, 0);
}

void ExplorerRobot::turnLeft(byte speed)
{
    analogWrite(arduinoPins.d5,0);
    analogWrite(arduinoPins.d6,speed);
    analogWrite(arduinoPins.d9,speed);
    analogWrite(arduinoPins.d10,0);
}

void ExplorerRobot::turnLeft(byte speedSx, byte speedDx)
{
    analogWrite(arduinoPins.d5,0);
    analogWrite(arduinoPins.d6,speedSx);
    analogWrite(arduinoPins.d9,speedDx);
    analogWrite(arduinoPins.d10,0);
}

void ExplorerRobot::stop()
{
    analogWrite(arduinoPins.d5, 0);
    analogWrite(arduinoPins.d6, 0);
    analogWrite(arduinoPins.d9, 0);
    analogWrite(arduinoPins.d10, 0);
}

void ExplorerRobot::button(bool direction) {}
void ExplorerRobot::analog(double threshold) {}
int ExplorerRobot::compass() {}
int ExplorerRobot::compass(byte pin) {}
int ExplorerRobot::accelerometer() {}
int ExplorerRobot::accelerometer(byte pin) {}


double ExplorerRobot::ultrasound(byte trigger, byte ultrasound)
{
    double tempoEcho = 0;

    //I generate a 10 micro second pulse for the trigger
    digitalWrite(trigger, LOW );     //Reset output
    delayMicroseconds(3);		    //Wait 3 microseconds
    digitalWrite(trigger, HIGH );    //Up level
    delayMicroseconds(10);          //Wait 10 microseconds
    digitalWrite(trigger, LOW );     //Reset output
    //Get the sensor time
    tempoEcho = pulseIn( ultrasound, HIGH,38000 );
    delay(10);

    //Convert the time in centimeter
    return 0.034 * tempoEcho / 2;
}

double ExplorerRobot::ultrasoundSx()
{
    return ExplorerRobot::ultrasound(arduinoPins.d3, arduinoPins.d11);
}


double ExplorerRobot::ultrasoundCx()
{
    return ExplorerRobot::ultrasound(arduinoPins.d3, arduinoPins.d13);
}

double ExplorerRobot::ultrasoundDx()
{
    return ExplorerRobot::ultrasound(arduinoPins.d3, arduinoPins.d12);
}

bool ExplorerRobot::ultrasound (byte trigger, byte echo, double threshold)
{
    double distance = 0;
    distance = ExplorerRobot::ultrasound(trigger, echo);
    return distance < threshold && distance > 0 ?true:false;
}

bool ExplorerRobot::ultrasoundSx (double threshold)
{
    double distance = 0;
    distance = ultrasoundSx();
    return distance < threshold && distance > 0 ?true:false;
}

bool ExplorerRobot::ultrasoundCx (double threshold)
{
    double distance = 0;
    distance = ultrasoundCx();
    return distance < threshold && distance > 0 ?true:false;
}

bool ExplorerRobot::ultrasoundDx (double threshold)
{

    double distance = 0;
    distance = ultrasoundDx();
    return distance < threshold && distance > 0?true:false;
}


double ExplorerRobot::pinAnalogRead(int pin)
{
    return analogRead(pin);
}

bool ExplorerRobot::pinDigitalRead(byte pin)
{
    return digitalRead(pin);
}

void ExplorerRobot::pinAnalogWrite(int pin, double value)
{
    return analogWrite(pin, value);
}

void ExplorerRobot::pinDigitalWrite(byte pin, bool value)
{
    return digitalWrite(pin, value);
}

//TODO DA Variare in base alla BOARD
double ExplorerRobot::light(byte pin)
{
    double vFoto = 0;
    vFoto = analogRead(pin);
    return vFoto * (RobotInfo::getVoltageMCU() / RobotInfo::getNumADconvertArduinoUno());
}

//TODO Inserire inverisone del valore

double ExplorerRobot::lightSx()
{
    return light(arduinoPins.a1);
}

double ExplorerRobot::lightCx()
{
    return light(arduinoPins.a2);
}

double ExplorerRobot::lightDx()
{
    return light(arduinoPins.a3);
}

/*
bool Ivotek_Robot::light(byte pin, double threshold)
{
    double vFoto = 0;
    vFoto = light(pin);
    return vFoto < threshold ? true: false;
}

bool Ivotek_Robot::lightSx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(a1,threshold);
    }
}

bool Ivotek_Robot::lightCx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(a2,threshold);
    }
}

bool Ivotek_Robot::lightDx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(a3,threshold);
    }
}

double Ivotek_Robot::batteryStatus()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return batteryStatus(a0);
    }
    return 0;
}

double Ivotek_Robot::batteryStatus(byte pin)
{
    double alim_digit = 0;
    double alimentazione = 0;
    alim_digit = analogRead(pin);
    alimentazione= alim_digit * (voltageMCU / numADconvertArduinoUno);
    return alimentazione * 2;
}

bool Ivotek_Robot::batteryStatus(double threshold)
{
    double trigger = 0;
    if(robotName=="POORV2")
    {
        trigger = batteryStatus(a0);
    }
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::batteryStatus(byte pin, double threshold)
{
    double trigger = 0;
    trigger = batteryStatus(pin);
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::genericSwitch(byte pin)
{
    bool value;
    value = digitalRead(pin);
    delay(10);
    value = digitalRead(pin);
    return value;

}

bool Ivotek_Robot::genericSwitch(bool invert, byte pin)
{
    bool value;
    value = digitalRead(pin);
    delay(10);
    value = digitalRead(pin);
    return invert ? !value : value;
}

bool Ivotek_Robot::switchSxFront()
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(d7);
    }
    return false;
}

bool Ivotek_Robot::switchDxFront()
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(d4);
    }
    return false;
}

bool Ivotek_Robot::switchSxFront(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(d7,invert);
    }
    return false;
}

bool Ivotek_Robot::switchDxFront(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(d4,invert);
    }
    return false;
}

#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
bool Ivotek_Robot::switchSxRear()
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(nucleoSwitchSxRear);
    }
    return false;
}

bool Ivotek_Robot::switchDxRear()
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(nucleoSwitchDxRear);
    }
    return false;
}

bool Ivotek_Robot::switchSxRear(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(nucleoSwitchSxRear, invert);
    }
    return false;
}

bool Ivotek_Robot::switchDxRear(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(nucleoSwitchDxRear, invert);
    }
    return false;
}
#endif // BOARD

byte Ivotek_Robot::temperature() {}
byte Ivotek_Robot::temperature(byte pin) {}
bool Ivotek_Robot::temperature(byte pin, double threshold) {}
int Ivotek_Robot::humidity() {}
int Ivotek_Robot::humidity(byte pin) {}
bool Ivotek_Robot::humidity(byte pin, double threshold) {}

void Ivotek_Robot::pinAnalogOn(byte pin)
{
    analogWrite(pin, 255);
}

void Ivotek_Robot::pinAnalogOff(byte pin)
{
    analogWrite(pin, 0);
}

void Ivotek_Robot::pinDigitalOn(byte pin)
{
    digitalWrite(pin, 255);
}

void Ivotek_Robot::pinDigitalOff(byte pin)
{
    digitalWrite(pin, LOW);
}

void Ivotek_Robot::ledSoundOn()
{
    pinDigitalOn(d8);
}

void Ivotek_Robot::ledSoundOff()
{
    pinDigitalOff(d8);
}

void Ivotek_Robot::ledLightOn()
{
    pinDigitalOn(d2);
}

void Ivotek_Robot::ledLightOff()
{
    pinDigitalOff(d2);
}

void Ivotek_Robot::ledGasOn()
{
    pinAnalogOn(a0);
}

void Ivotek_Robot::ledGasOff()
{
    pinAnalogOff(a0);
}

double Ivotek_Robot::sound()
{
    return pinAnalogRead(a4);
}

bool Ivotek_Robot::sound(double threshold)
{
    double trigger = 0;
    trigger = sound();
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::sound(double threshold, bool invert)
{
    double trigger = 0;
    trigger = sound();
    if(invert == false)
    {
        return trigger < threshold?true:false;
    }
    else
    {
        return trigger < threshold?false:true;
    }

}

bool Ivotek_Robot::sound(int pin, double threshold)
{
    double trigger = 0;
    trigger = pinAnalogRead(pin);
    return trigger < threshold?true:false;
}

#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
double Ivotek_Robot::sound_1()
{
    return pinAnalogRead(a6);
}

bool Ivotek_Robot::sound_1(double threshold)
{
    double trigger = 0;
    trigger = sound();
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::sound_1(double threshold, bool invert)
{
    double trigger = 0;
    trigger = sound();
    if(invert == false)
    {
        return trigger < threshold?true:false;
    }
    else
    {
        return trigger < threshold?false:true;
    }
}

bool Ivotek_Robot::sound_1(int pin, double threshold)
{
    double trigger = 0;
    trigger = pinAnalogRead(pin);
    return trigger < threshold?true:false;
}
#endif

double Ivotek_Robot::gasAlcool()
{
    return pinAnalogRead(a5);
}

bool Ivotek_Robot::gasAlcool(double threshold)
{
    double trigger = 0;
    trigger = sound();
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::gasAlcool(int pin, double threshold)
{
    double trigger = 0;
    trigger = pinAnalogRead(pin);
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::gasAlcool(double threshold, bool invert)
{
    double trigger = 0;
    trigger = gasAlcool();
    if(invert == false)
    {
        return trigger < threshold?true:false;
    }
    else
    {
        return trigger < threshold?false:true;
    }

}

#if BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
double Ivotek_Robot::gasAlcool_1()
{
    return pinAnalogRead(a7);
}

bool Ivotek_Robot::gasAlcool_1(double threshold)
{
    double trigger = 0;
    trigger = sound();
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::gasAlcool_1(int pin, double threshold)
{
    double trigger = 0;
    trigger = pinAnalogRead(pin);
    return trigger < threshold?true:false;
}

bool Ivotek_Robot::gasAlcool_1(double threshold, bool invert)
{
    double trigger = 0;
    trigger = gasAlcool();
    if(invert == false)
    {
        return trigger < threshold?true:false;
    }
    else
    {
        return trigger < threshold?false:true;
    }

}
#endif

void Ivotek_Robot::getVersion()
{
    Serial.print("Robot: ");
    Serial.print(robotName);
    Serial.print(" -- Board: ");
    Serial.print(boardName);
    Serial.print(" -- Version: ");
    Serial.println(VERSION);
}
*/


void ExplorerRobot::getVersion()
{
    Serial.print("Robot: ");
    Serial.print(RobotInfo::getRobotName());
    Serial.print(" -- Version: ");
    Serial.println(RobotInfo::getVersion());
}

