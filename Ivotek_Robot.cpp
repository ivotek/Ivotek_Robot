//*********************************************************
//Programma test per il controllo dei robot realizzati da Daniele Loddo alias Ivotek
//
//Realizzato da Daniele Loddo alias Ivotek
//data: 25/08/2024
//Versione 0.0.1
//Sito web: www.ivotek.it
//
//
//PIN per Snail
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

// PIN per Explorer
//PIN 5 - 6  Motore sinistro
//PIN 9 - 10 Morore destro
//PIN 3 Trigger ultrasuoni
//PIN 11 Ultrasuoni sinistro
//PIN 12 Ultrasuoni centrale
//PIN 13 Ultrasuoni destro
//PIN A1 fotoresistenza sinistra
//PIN A2 fotoresistenza centrale
//PIN A3 fotoresistenza destra
//PIN 4 Contatto Dx anteriore
//PIN 7 contatto Sx anteriore
//PIN 2 Contatto Dx posteriore
//PIN 8 contatto Sx posteriore
//*********************************************************

#include "Ivotek_Robot.h"

String robotName = "";

void Ivotek_Robot::initialization(String name)
{
    robotName = name;

    if(robotName == "default" || robotName == "snail" || robotName == "explorer" )
    {
        pinMode(5,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(9,OUTPUT);
        pinMode(10,OUTPUT);
    }

    if(robotName=="snail")
    {
        pinMode(A0,INPUT_PULLUP);
        pinMode(A1,INPUT_PULLUP);
        pinMode(A2,INPUT_PULLUP);
        pinMode(A3,INPUT_PULLUP);
    }

    if(robotName=="poor")
    {
        pinMode(5,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(9,OUTPUT);
        pinMode(10,OUTPUT);
        pinMode(A0,INPUT_PULLUP);
        pinMode(7,OUTPUT);
        pinMode(2,OUTPUT);
        pinMode(8,OUTPUT);
        pinMode(A1,INPUT_PULLUP);
        pinMode(A2,INPUT_PULLUP);
        pinMode(A3,INPUT_PULLUP);
    }

    if(robotName == "explorer")
    {
        pinMode(4,INPUT_PULLUP);
        pinMode(7,INPUT_PULLUP);
        pinMode(2,INPUT_PULLUP);
        pinMode(8,INPUT_PULLUP);
        pinMode(A1,INPUT_PULLUP);
        pinMode(A2,INPUT_PULLUP);
        pinMode(A3,INPUT_PULLUP);
        pinMode(4,INPUT_PULLUP);
        pinMode(7,INPUT_PULLUP);
        pinMode(2,INPUT_PULLUP);
        pinMode(8,INPUT_PULLUP);
    }

}

void Ivotek_Robot::forwards(void)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,255);
        analogWrite(6,LOW);
        analogWrite(9,255);
        analogWrite(10,LOW);
    }

}

void Ivotek_Robot::backwards(void)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,255);
        analogWrite(9,LOW);
        analogWrite(10,255);
    }

}

void Ivotek_Robot::turnRight(void)
{
    if(robotName == "default" || robotName == "explorer")
    {
         analogWrite(5,255);
         analogWrite(6,LOW);
         analogWrite(9,LOW);
         analogWrite(10,255);
    }

}
void Ivotek_Robot::turnLeft(void)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,255);
        analogWrite(9,255);
        analogWrite(10,LOW);
    }

}

void Ivotek_Robot::forwards(byte speed)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,speed);
        analogWrite(6,LOW);
        analogWrite(9,speed);
        analogWrite(10,LOW);
    }

}
void Ivotek_Robot::backwards(byte speed)
{
    if(robotName == "default" ||robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,speed);
        analogWrite(9,LOW);
        analogWrite(10,speed);
    }

}

void Ivotek_Robot::forwards(byte speedSx, byte speedDx)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,speedSx);
        analogWrite(6,LOW);
        analogWrite(9,speedDx);
        analogWrite(10,LOW);
    }

}
void Ivotek_Robot::backwards(byte speedSx, byte speedDx)
{
    if(robotName == "default" ||robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,speedSx);
        analogWrite(9,LOW);
        analogWrite(10,speedDx);
    }

}

void Ivotek_Robot::turnRight(byte speed)
{
    if(robotName == "default" || robotName == "explorer")
    {
         analogWrite(5,speed);
         analogWrite(6,LOW);
         analogWrite(9,LOW);
         analogWrite(10,speed);
    }

}

void Ivotek_Robot::turnLeft(byte speed)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,speed);
        analogWrite(9,speed);
        analogWrite(10,LOW);
    }

}

void Ivotek_Robot::turnLeft(byte speedSx, byte speedDx)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,speedSx);
        analogWrite(9,speedDx);
        analogWrite(10,LOW);
    }

}

void Ivotek_Robot::turnRight(byte speedSx, byte speedDx)
{
    if(robotName == "default" || robotName == "explorer")
    {
         analogWrite(5,speedSx);
         analogWrite(6,LOW);
         analogWrite(9,LOW);
         analogWrite(10,speedDx);
    }

}

void Ivotek_Robot::stop(void)
{
    if(robotName == "default" || robotName == "explorer")
    {
        analogWrite(5,LOW);
        analogWrite(6,LOW);
        analogWrite(9,LOW);
        analogWrite(10,LOW);
    }

}


//void Ivotek_Robot::forwards(int speed, int pin) {}
//void Ivotek_Robot::backwards(int speed, int pin) {}

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
    delayMicroseconds( 10 );          //Wait 10 microseconds
    digitalWrite(trigger, LOW );     //Reset output
    //Get the sensor time
    tempoEcho = pulseIn( ultrasound, HIGH,38000 );
    delay(10);

    //Convert the time in centimeter
    return 0.034 * tempoEcho / 2;

}

double Ivotek_Robot::ultrasoundSx()
{

    if(robotName=="poor")
    {
        return Ivotek_Robot::ultrasound(3, 11);
    }
}

double Ivotek_Robot::ultrasoundCx()
{
    if(robotName=="poor")
    {
        return Ivotek_Robot::ultrasound(3, 12);
    }
}
double Ivotek_Robot::ultrasoundDx()
{
    if(robotName=="poor")
    {
        return Ivotek_Robot::ultrasound(3, 13);
    }
}

bool Ivotek_Robot::ultrasound (byte trigger, byte ultrasound, double threshold)
{
    double distance = 0;
    distance = Ivotek_Robot::ultrasound(trigger, ultrasound);

    return distance < threshold?true:false;
}

bool Ivotek_Robot::ultrasoundSx (double threshold)
{
    double distance = 0;
    distance = ultrasoundSx();

    return distance < threshold?true:false;
}

bool Ivotek_Robot::ultrasoundCx (double threshold)
{
    double distance = 0;
    distance = ultrasoundCx();

    return distance < threshold?true:false;
}

bool Ivotek_Robot::ultrasoundDx (double threshold)
{
    double distance = 0;
    distance = ultrasoundDx();

    return distance < threshold?true:false;
}

double Ivotek_Robot::light(byte pin)
{
    double vFoto = 0;
    vFoto = analogRead(pin);

    //Li converto in volt
    return vFoto * (5.0 / 1024.0);

}

double Ivotek_Robot::lightSx()
{
    if(robotName=="poor")
    {
        return light(A1);
    }
}

double Ivotek_Robot::lightCx()
{
    if(robotName=="poor")
    {
        return light(A2);
    }
}

double Ivotek_Robot::lightDx()
{
    if(robotName=="poor")
    {
        return light(A3);
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
    if(robotName=="poor")
    {
        return light(A1,threshold);
    }
}

bool Ivotek_Robot::lightCx(double threshold)
{
    if(robotName=="poor")
    {
        return light(A2,threshold);
    }
}
bool Ivotek_Robot::lightDx(double threshold)
{
    if(robotName=="poor")
    {
        return light(A3,threshold);
    }
}

double Ivotek_Robot::battery()
{
    if(robotName=="poor")
    {
        return battery(A0);
    }

    return 0;
}

double Ivotek_Robot::battery(byte pin)
{
    double alim_digit = 0;
    double alimentazione = 0;
    //I take the data from the pin port to know the power level
    alim_digit = analogRead(pin);
    //Convert the binary code in analogic code
    alimentazione= alim_digit * (5.0 / 1024.0);
    //Multiply by two to get the battery pack voltage
    return alimentazione * 2;
}

bool Ivotek_Robot::battery(double threshold)
{
    double trigger = 0;
    if(robotName=="poor")
    {
        trigger = battery(A0);
    }

    return trigger < threshold?true:false;

}


bool Ivotek_Robot::battery(byte pin, double threshold)
{
    double trigger = 0;

    trigger = battery(pin);

    return trigger < threshold?true:false;
}

bool Ivotek_Robot::genericSwitch(byte pin){
    bool value;
    value = digitalRead(pin);
    delay(10);
    value = digitalRead(pin);
    return value;
}

bool Ivotek_Robot::genericSwitch(bool invert, byte pin){
    bool value;
    value = digitalRead(pin);
    delay(10);
    value = digitalRead(pin);
    return invert ? !value : value;
}

bool Ivotek_Robot::switchSxFront(){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(7);
        delay(10);
        value = digitalRead(7);
        return value;
    }

    return false;
}

bool Ivotek_Robot::switchDxFront(){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(4);
        delay(10);
        value = digitalRead(4);
        return value;
    }
    
    return false;
}

bool Ivotek_Robot::switchSxFront(bool invert){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(7);
        delay(10);
        value = digitalRead(7);
        return invert ? !value : value;
    }

    return false;
}

bool Ivotek_Robot::switchDxFront(bool invert){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(4);
        delay(10);
        value = digitalRead(4);
        return invert ? !value : value;
    }

    return false;
}

bool Ivotek_Robot::switchSxRear(){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(8);
        delay(10);
        value = digitalRead(8);
        return value;
    }

    return false;
}

bool Ivotek_Robot::switchDxRear(){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(2);
        delay(10);
        value = digitalRead(2);
        return value;
    }

    return false;
}

bool Ivotek_Robot::switchSxRear(bool invert){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(8);
        delay(10);
        value = digitalRead(8);
        return invert ? !value : value;
    }

    return false;
}

bool Ivotek_Robot::switchDxRear(bool invert){
    bool value;
    if(robotName=="explorer")
    {
        value = digitalRead(2);
        delay(10);
        value = digitalRead(2);
        return invert ? !value : value;
    }

    return false;
}

byte Ivotek_Robot::temperature() {}
byte Ivotek_Robot::temperature(byte pin) {}
bool Ivotek_Robot::temperature(byte pin, double threshold) {}
int Ivotek_Robot::humidity() {}
int Ivotek_Robot::humidity(byte pin) {}
bool Ivotek_Robot::humidity(byte pin, double threshold) {}
