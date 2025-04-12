//Includiamo la libreria se non è già stata inclusa
//da un altra libreria
#ifndef Ivotek_Robot_H
#define Ivotek_Robot_H

//Includiamo la libreria di Arduino
#include "Arduino.h"

class Ivotek_Robot
{
private:
    byte pinGlobal;  // Pin dove è collegato il led

public:
    void initialization(String name);

    void forwards();
    void backwards();
    void turnRight();
    void turnLeft();
    void stop();

    void forwards(byte speed);
    void backwards(byte speed);
    void turnRight(byte speed);
    void turnLeft(byte speed);
    void turnRight(byte speedSx, byte speedDx);
    void turnLeft(byte speedSx, byte speedDx);
    void forwards(byte speedSx, byte speedDx);
    void backwards(byte speedSx, byte speedDx);
    //void forwards(byte speed, byte pin);
    //void backwards(byte speed, byte pin);

    void button(bool direction);
    void analog(double threshold);

    int compass();
    int compass(byte pin);
    int accelerometer();
    int accelerometer(byte pin);


    double ultrasound(byte trigger, byte ultrasound);
    bool ultrasound (byte trigger, byte ultrasound, double threshold);
    double ultrasoundSx();
    bool ultrasoundSx(double threshold);
    double ultrasoundDx();
    bool ultrasoundDx(double threshold);
    double ultrasoundCx();
    bool ultrasoundCx(double threshold);


    double lightSx();
    double lightCx();
    double lightDx();
    double light(byte pin);
    bool light(byte pin, double threshold);
    bool lightSx(double threshold);
    bool lightCx(double threshold);
    bool lightDx(double threshold);

    double battery();
    double battery(byte pin);
    bool battery(double threshold);
    bool battery(byte pin, double threshold);

    byte temperature();
    byte temperature(byte pin);
    bool temperature(byte pin, double threshold);
    int humidity();
    int humidity(byte pin);
    bool humidity(byte pin, double threshold);
    
    bool switchSx();
    bool switchDx();
    bool switchSx(bool invert);
    bool switchDx(bool invert);




};

#endif // Ivotek_Robot_H
