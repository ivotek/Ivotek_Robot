#include <Arduino.h>
#include "ExplorerRobot.h"
#include "../Config/RobotInfo.h"

ExplorerRobot::ExplorerRobot()
{
    // Inizializzazione dei pin
#if BOARD == ARDUINO_UNO || BOARD == ARDUINO_NANO || BOARD == NUCLEO_F030R8
    pins.arduinoDigit5 = 5;
    pins.arduinoDigit6 = 6;
    pins.arduinoDigit9 = 9;
    pins.arduinoDigit10 = 10;
#endif

#if BOARD == ARDUINO_NANO
    pins.arduinoAnalog6 = A6;
    pins.arduinoAnalog7 = A7;
#endif

#if BOARD == NUCLEO_F030R8 || BOARD == NUCLEO_F401RE
    pins.arduinoAnalog6 = PC2;
    pins.arduinoAnalog7 = PC3;
    pins.nucleoSwitchSxRear = PC15;
    pins.nucleoSwitchDxRear = PC14;
#endif
    //#else
    //    #error "The selected card is not supported. Please choose a card from the config.h file.."
    //#endif
}

void ExplorerRobot::initialize()
{
    pinMode(pins.arduinoDigit5, OUTPUT);
    pinMode(pins.arduinoDigit6, OUTPUT);
    pinMode(pins.arduinoDigit9, OUTPUT);
    pinMode(pins.arduinoDigit10, OUTPUT);
}

void ExplorerRobot::forwards()
{
    analogWrite(pins.arduinoDigit5, 255);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 255);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::forwards(byte speed)
{
    analogWrite(pins.arduinoDigit5,speed);
    analogWrite(pins.arduinoDigit6,0);
    analogWrite(pins.arduinoDigit9,speed);
    analogWrite(pins.arduinoDigit10,0);
}

void ExplorerRobot::forwards(byte speedSx, byte speedDx)
{
    analogWrite(pins.arduinoDigit5,speedSx);
    analogWrite(pins.arduinoDigit6,0);
    analogWrite(pins.arduinoDigit9,speedDx);
    analogWrite(pins.arduinoDigit10,0);

}

void ExplorerRobot::backwards()
{
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 255);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 255);
}


void ExplorerRobot::backwards(byte speed)
{
    analogWrite(pins.arduinoDigit5,0);
    analogWrite(pins.arduinoDigit6,speed);
    analogWrite(pins.arduinoDigit9,0);
    analogWrite(pins.arduinoDigit10,speed);
}

void ExplorerRobot::backwards(byte speedSx, byte speedDx)
{
    analogWrite(pins.arduinoDigit5,0);
    analogWrite(pins.arduinoDigit6,speedSx);
    analogWrite(pins.arduinoDigit9,0);
    analogWrite(pins.arduinoDigit10,speedDx);
}


void ExplorerRobot::turnRight(byte speed)
{
    analogWrite(pins.arduinoDigit5,speed);
    analogWrite(pins.arduinoDigit6,0);
    analogWrite(pins.arduinoDigit9,0);
    analogWrite(pins.arduinoDigit10,speed);
}

void ExplorerRobot::turnLeft(byte speed)
{
    analogWrite(pins.arduinoDigit5,0);
    analogWrite(pins.arduinoDigit6,speed);
    analogWrite(pins.arduinoDigit9,speed);
    analogWrite(pins.arduinoDigit10,0);
}

void ExplorerRobot::turnLeft(byte speedSx, byte speedDx)
{
    analogWrite(pins.arduinoDigit5,0);
    analogWrite(pins.arduinoDigit6,speedSx);
    analogWrite(pins.arduinoDigit9,speedDx);
    analogWrite(pins.arduinoDigit10,0);
}


/*
void Ivotek_Robot::turnRight(byte speedSx, byte speedDx)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(arduinoDigit5,speedSx);
        analogWrite(arduinoDigit6,0);
        analogWrite(arduinoDigit9,0);
        analogWrite(arduinoDigit10,speedDx);
    }
}

void Ivotek_Robot::stop(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(arduinoDigit5,0);
        analogWrite(arduinoDigit6,0);
        analogWrite(arduinoDigit9,0);
        analogWrite(arduinoDigit10,0);
    }
}

void Ivotek_Robot::button(bool direction) {}

void Ivotek_Robot::analog(double threshold) {}

int Ivotek_Robot::compass() {}
int Ivotek_Robot::compass(byte pin) {}
int Ivotek_Robot::accelerometer() {}
int Ivotek_Robot::accelerometer(byte pin) {}

double Ivotek_Robot::ultrasound(byte trigger, byte ultrasound)
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

double Ivotek_Robot::ultrasoundSx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return Ivotek_Robot::ultrasound(arduinoDigit3, arduinoDigit11);
    }
}

double Ivotek_Robot::ultrasoundCx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return Ivotek_Robot::ultrasound(arduinoDigit3, arduinoDigit13);
    }
}

double Ivotek_Robot::ultrasoundDx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return Ivotek_Robot::ultrasound(arduinoDigit3, arduinoDigit12);
    }
}

bool Ivotek_Robot::ultrasound (byte trigger, byte echo, double threshold)
{
    if(boardName == "ARDUINO_UNO" || boardName == "DEFAULT")
    {
        double distance = 0;
        distance = Ivotek_Robot::ultrasound(trigger, echo);
        return distance < threshold && distance > 0 ?true:false;
    }
}

bool Ivotek_Robot::ultrasoundSx (double threshold)
{
    double distance = 0;
    distance = ultrasoundSx();
    return distance < threshold && distance > 0 ?true:false;
}

bool Ivotek_Robot::ultrasoundCx (double threshold)
{
    double distance = 0;
    distance = ultrasoundCx();
    return distance < threshold && distance > 0 ?true:false;
}

bool Ivotek_Robot::ultrasoundDx (double threshold)
{

    double distance = 0;
    distance = ultrasoundDx();

    return distance < threshold && distance > 0?true:false;
}

double Ivotek_Robot::pinAnalogRead(int pin)
{
    return analogRead(pin);
}

bool Ivotek_Robot::pinDigitalRead(byte pin)
{
    return digitalRead(pin);
}

void Ivotek_Robot::pinAnalogWrite(byte pin, double value)
{
    return analogWrite(pin, value);
}

void Ivotek_Robot::pinDigitalWrite(byte pin, bool value)
{
    return digitalWrite(pin, value);
}

double Ivotek_Robot::light(byte pin)
{
    double vFoto = 0;
    vFoto = analogRead(pin);
    return vFoto * (voltageMCU / numADconvertArduinoUno);
}

//TODO Inserire inverisone del valore

double Ivotek_Robot::lightSx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(arduinoAnalog1);
    }
}

double Ivotek_Robot::lightCx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(arduinoAnalog2);
    }
}

double Ivotek_Robot::lightDx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(arduinoAnalog3);
    }
}

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
        return light(arduinoAnalog1,threshold);
    }
}

bool Ivotek_Robot::lightCx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(arduinoAnalog2,threshold);
    }
}

bool Ivotek_Robot::lightDx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(arduinoAnalog3,threshold);
    }
}

double Ivotek_Robot::batteryStatus()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return batteryStatus(arduinoAnalog0);
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
        trigger = batteryStatus(arduinoAnalog0);
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
        return genericSwitch(arduinoDigit7);
    }
    return false;
}

bool Ivotek_Robot::switchDxFront()
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(arduinoDigit4);
    }
    return false;
}

bool Ivotek_Robot::switchSxFront(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(arduinoDigit7,invert);
    }
    return false;
}

bool Ivotek_Robot::switchDxFront(bool invert)
{
    if(robotName=="EXPLORER")
    {
        return genericSwitch(arduinoDigit4,invert);
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
    pinDigitalOn(arduinoDigit8);
}

void Ivotek_Robot::ledSoundOff()
{
    pinDigitalOff(arduinoDigit8);
}

void Ivotek_Robot::ledLightOn()
{
    pinDigitalOn(arduinoDigit2);
}

void Ivotek_Robot::ledLightOff()
{
    pinDigitalOff(arduinoDigit2);
}

void Ivotek_Robot::ledGasOn()
{
    pinAnalogOn(arduinoAnalog0);
}

void Ivotek_Robot::ledGasOff()
{
    pinAnalogOff(arduinoAnalog0);
}

double Ivotek_Robot::sound()
{
    return pinAnalogRead(arduinoAnalog4);
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
    return pinAnalogRead(arduinoAnalog6);
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
    return pinAnalogRead(arduinoAnalog5);
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
    return pinAnalogRead(arduinoAnalog7);
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

void ExplorerRobot::turnLeft()
{
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 255);
    analogWrite(pins.arduinoDigit9, 255);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::turnRight()
{
    analogWrite(pins.arduinoDigit5, 255);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 255);
}

void ExplorerRobot::stop()
{
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::getVersion()
{
    Serial.print("Robot: ");
    Serial.print(RobotInfo::getRobotName());
    Serial.print(" -- Version: ");
    Serial.println(RobotInfo::getVersion());
}

