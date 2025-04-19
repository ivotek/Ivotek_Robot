//*********************************************************
//Libreria per il controllo dei robot realizzati da Daniele Loddo alias Ivotek
//
//Realizzato da Daniele Loddo alias Ivotek
//data: 25/08/2024
//Versione 1.0.0
//Sito web: www.ivotek.it
//
//
//PIN per SNAIL
//PIN 5 - 6  Motore sinistro
//PIN 9 - 10 Motore destro
//PIN A3 Sensore sinistro esterno
//PIN A2 Sensore sinistro interno
//PIN A1 Sensore destro interno
//PIN A0 Sensore destro esterno
//
//PIN per Poor V2
//PIN A0 controllo batteria
//PIN 3 Trigger ultrasuoni
//PIN 11 Ultrasuoni sinistro
//PIN 12 Ultrasuoni centrale
//PIN 13 Ultrasuoni destro
//PIN 4 Linea DX
//PIN 7 Linea SX
//PIN 2 Linea CDX
//PIN 8 Linea CSX
//PIN A1 fotoresistenza sinistra
//PIN A2 fotoresistenza centrale
//PIN A3 fotoresistenza destra

//PIN per Explorer
//PIN 5 - 6  Motore sinistro -- PA5 - PA6
//PIN 9 - 10 Morore destro -- PA9 - PA10
//PIN 3 Trigger ultrasuoni in comune
//PIN 11 Ultrasuoni sinistro
//PIN 12 Ultrasuoni destro
//PIN 13 Ultrasuoni centro
//PIN A1 fotoresistenza sinistra
//PIN A2 fotoresistenza centrale
//PIN A3 fotoresistenza destra
//PIN 4 Contatto Dx anteriore -- PA4
//PIN 7 Contatto Sx anteriore -- PA7
//PIN 2 Contatto Dx posteriore -- PA2
//PIN 8 Contatto Sx posteriore -- PA8
//PIN 0 Led luce
//PIN 1 Led suono
//PIN A0 Led gas
//PIN A4 Ricezione suono
//PIN A5 Ricezione gas
//*********************************************************

#include "Ivotek_Robot.h"

void Ivotek_Robot::initialization(String name, String board)
{
    name.toUpperCase();
    board.toUpperCase();
    robotName = name;
    boardName = board;
    Serial.begin(baudRateSerial);

    if(robotName == "DEFAULT" || robotName == "SNAIL" || robotName == "EXPLORER" || robotName == "POORV2")
    {
        pinMode(digit5,OUTPUT);
        pinMode(digit6,OUTPUT);
        pinMode(digit9,OUTPUT);
        pinMode(digit10,OUTPUT);
    }

    if(robotName=="SNAIL" || robotName == "EXPLORER" || robotName=="POORV2")
    {
        pinMode(digit4,INPUT_PULLUP);
        pinMode(digit7,INPUT_PULLUP);
        pinMode(digit2,INPUT_PULLUP);
        pinMode(digit8,INPUT_PULLUP);
        pinMode(A0,INPUT_PULLUP);
        pinMode(A1,INPUT_PULLUP);
        pinMode(A2,INPUT_PULLUP);
        pinMode(A3,INPUT_PULLUP);
        pinMode(digit3,OUTPUT);
        pinMode(digit11,INPUT_PULLUP);
        pinMode(digit12,INPUT_PULLUP);
        pinMode(digit13,INPUT_PULLUP);
    }

}

void Ivotek_Robot::forwards(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,HIGH);
        analogWrite(digit6,LOW);
        analogWrite(digit9,HIGH);
        analogWrite(digit10,LOW);
    }

}

void Ivotek_Robot::backwards(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,HIGH);
        analogWrite(digit9,LOW);
        analogWrite(digit10,HIGH);
    }

}

void Ivotek_Robot::turnRight(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,HIGH);
        analogWrite(digit6,LOW);
        analogWrite(digit9,LOW);
        analogWrite(digit10,HIGH);
    }

}
void Ivotek_Robot::turnLeft(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,HIGH);
        analogWrite(digit9,HIGH);
        analogWrite(digit10,LOW);
    }

}

void Ivotek_Robot::forwards(byte speed)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,speed);
        analogWrite(digit6,LOW);
        analogWrite(digit9,speed);
        analogWrite(digit10,LOW);
    }

}
void Ivotek_Robot::backwards(byte speed)
{
    if(robotName == "DEFAULT" ||robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,speed);
        analogWrite(digit9,LOW);
        analogWrite(digit10,speed);
    }

}

void Ivotek_Robot::forwards(byte speedSx, byte speedDx)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,speedSx);
        analogWrite(digit6,LOW);
        analogWrite(digit9,speedDx);
        analogWrite(digit10,LOW);
    }

}
void Ivotek_Robot::backwards(byte speedSx, byte speedDx)
{
    if(robotName == "DEFAULT" ||robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,speedSx);
        analogWrite(digit9,LOW);
        analogWrite(digit10,speedDx);
    }

}

void Ivotek_Robot::turnRight(byte speed)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,speed);
        analogWrite(digit6,LOW);
        analogWrite(digit9,LOW);
        analogWrite(digit10,speed);
    }

}

void Ivotek_Robot::turnLeft(byte speed)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,speed);
        analogWrite(digit9,speed);
        analogWrite(digit10,LOW);
    }

}

void Ivotek_Robot::turnLeft(byte speedSx, byte speedDx)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,speedSx);
        analogWrite(digit9,speedDx);
        analogWrite(digit10,LOW);
    }

}

void Ivotek_Robot::turnRight(byte speedSx, byte speedDx)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,speedSx);
        analogWrite(digit6,LOW);
        analogWrite(digit9,LOW);
        analogWrite(digit10,speedDx);
    }

}

void Ivotek_Robot::stop(void)
{
    if(robotName == "DEFAULT" || robotName == "EXPLORER")
    {
        analogWrite(digit5,LOW);
        analogWrite(digit6,LOW);
        analogWrite(digit9,LOW);
        analogWrite(digit10,LOW);
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
        return Ivotek_Robot::ultrasound(digit3, digit11);
    }
}

double Ivotek_Robot::ultrasoundCx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return Ivotek_Robot::ultrasound(digit3, digit13);
    }
}
double Ivotek_Robot::ultrasoundDx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return Ivotek_Robot::ultrasound(digit3, digit12);
    }
}

bool Ivotek_Robot::ultrasound (byte trigger, byte echo, double threshold)
{
    double distance = 0;
    distance = Ivotek_Robot::ultrasound(trigger, echo);

    return distance < threshold && distance > 0 ?true:false;
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

double Ivotek_Robot::pinAnalogRead(byte pin){
    return analogRead(pin);
}

bool Ivotek_Robot::pinDigitalRead(byte pin){
    return digitalRead(pin);
}

void Ivotek_Robot::pinAnalogWrite(byte pin, double value){
    return analogWrite(pin, value);
}

void Ivotek_Robot::pinDigitalWrite(byte pin, bool value){
    return digitalWrite(pin, value);
}

double Ivotek_Robot::light(byte pin)
{
    double vFoto = 0;
    vFoto = analogRead(pin);

    return vFoto * (voltageMCU / numADconvert);

}

//TODO Inserire inverisone del valore

double Ivotek_Robot::lightSx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(analog1);
    }
}

double Ivotek_Robot::lightCx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(analog2);
    }
}

double Ivotek_Robot::lightDx()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(analog3);
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
        return light(analog1,threshold);
    }
}

bool Ivotek_Robot::lightCx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(analog2,threshold);
    }
}
bool Ivotek_Robot::lightDx(double threshold)
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return light(analog3,threshold);
    }
}


double Ivotek_Robot::batteryStatus()
{
    if(robotName=="POORV2" || robotName=="EXPLORER")
    {
        return batteryStatus(analog0);
    }

    return 0;
}

double Ivotek_Robot::batteryStatus(byte pin)
{
    double alim_digit = 0;
    double alimentazione = 0;
    //I take the data from the pin port to know the power level
    alim_digit = analogRead(pin);
    //Convert the binary code in analogic code
    alimentazione= alim_digit * (voltageMCU / numADconvert);
    //Multiply by two to get the battery pack voltage
    return alimentazione * 2;
}


bool Ivotek_Robot::batteryStatus(double threshold)
{
    double trigger = 0;
    if(robotName=="POORV2")
    {
        trigger = batteryStatus(analog0);
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
        return genericSwitch(digit7);
    }

    return false;
}

bool Ivotek_Robot::switchDxFront()
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit4);
    }

    return false;
}

bool Ivotek_Robot::switchSxFront(bool invert)
{

    if(robotName=="EXPLORER")
    {
       return genericSwitch(digit7,invert);
    }

    return false;
}

bool Ivotek_Robot::switchDxFront(bool invert)
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit4,invert);
    }

    return false;
}

bool Ivotek_Robot::switchSxRear()
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit8);
    }

    return false;
}

bool Ivotek_Robot::switchDxRear()
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit2);
    }

    return false;
}

bool Ivotek_Robot::switchSxRear(bool invert)
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit8, invert);
    }

    return false;
}

bool Ivotek_Robot::switchDxRear(bool invert)
{

    if(robotName=="EXPLORER")
    {
        return genericSwitch(digit2, invert);
    }

    return false;
}

byte Ivotek_Robot::temperature() {}
byte Ivotek_Robot::temperature(byte pin) {}
bool Ivotek_Robot::temperature(byte pin, double threshold) {}
int Ivotek_Robot::humidity() {}
int Ivotek_Robot::humidity(byte pin) {}
bool Ivotek_Robot::humidity(byte pin, double threshold) {}

void Ivotek_Robot::pinAnalogOn(byte pin){
    analogWrite(pin, HIGH);
}

void Ivotek_Robot::pinAnalogOff(byte pin){
    analogWrite(pin, LOW);
}

void Ivotek_Robot::pinDigitalOn(byte pin){
    digitalWrite(pin, HIGH);
}

void Ivotek_Robot::pinDigitalOff(byte pin){
    digitalWrite(pin, LOW);
}

void Ivotek_Robot::ledSoundOn(){
    pinDigitalOn(digit0);
}

void Ivotek_Robot::ledSoundOff(){
    pinDigitalOff(digit0);
}

void Ivotek_Robot::ledLightOn(){
    pinDigitalOn(digit1);
}

void Ivotek_Robot::ledLightOff(){
    pinDigitalOff(digit1);
}

void Ivotek_Robot::ledGasOn(){
    pinAnalogOn(analog0);
}

void Ivotek_Robot::ledGasOff(){
    pinAnalogOff(analog0);
}

void Ivotek_Robot::getVersion()
{
    Serial.print("Robot: ");
    Serial.print(robotName);
    Serial.print(" -- Board: ");
    Serial.print(boardName);
    Serial.print(" -- Version: ");
    Serial.println(VERSION);
}
