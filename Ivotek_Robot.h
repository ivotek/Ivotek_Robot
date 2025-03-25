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

    void forwards(int speed);
    void backwards(int speed);
    void turnRight(int speed);
    void turnLeft(int speed);
    void turnRight(int speedSx, int speedDx);
    void turnLeft(int speedSx, int speedDx);
    void forwards(int speedSx, int speedDx);
    void backwards(int speedSx, int speedDx);
    void forwards(int speed, int pin);
    void backwards(int speed, int pin);

    void button(bool direction);
    void analog(double threshold);

    int compass();
    int compass(int pin);
    int accelerometer();
    int accelerometer(int pin);


    double ultrasound(int trigger, int ultrasound);
    bool ultrasound (int trigger, int ultrasound, double threshold);
    double ultrasoundSx();
    bool ultrasoundSx(double threshold);
    double ultrasoundDx();
    bool ultrasoundDx(double threshold);
    double ultrasoundCx();
    bool ultrasoundCx(double threshold);


    double lightSx();
    double lightCx();
    double lightDx();
    double light(int pin);
    bool light(int pin, double threshold);
    bool lightSx(double threshold);
    bool lightCx(double threshold);
    bool lightDx(double threshold);

    double battery();
    double battery(int pin);
    bool battery(double threshold);
    bool battery(int pin, double threshold);

    int temperature();
    int temperature(int pin);
    bool temperature(int pin, double threshold);
    int humidity();
    int humidity(int pin);
    bool humidity(int pin, double threshold);




};

#endif // Ivotek_Robot_H
