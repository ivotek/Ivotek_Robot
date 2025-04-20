//Includiamo la libreria se non è già stata inclusa
//da un altra libreria
#ifndef Ivotek_Robot_H
#define Ivotek_Robot_H

#include "Arduino.h"
#include "Config.h"

class Ivotek_Robot
{
private:
    String robotName = "DEFAULT";
    String boardName = "DEFAULT";
    const String VERSION = "1.0.0";
    const double voltageMCU = 5.0;
    const int numADconvert = 1024;
    const int baudRateSerial = 9600;

    byte arduinoDigit0 = 0;
    byte arduinoDigit1 = 1;
    byte arduinoDigit2 = 2;
    byte arduinoDigit3 = 3;
    byte arduinoDigit4 = 4;
    byte arduinoDigit7 = 7;
    byte arduinoDigit8 = 8;
    byte arduinoDigit11 = 11;
    byte arduinoDigit12 = 12;
    byte arduinoDigit13 = 13;
    byte arduinoDigit14 = 14;
    byte arduinoDigit15 = 15;
    byte arduinoAnalog0 = A0;
    byte arduinoAnalog1 = A1;
    byte arduinoAnalog2 = A2;
    byte arduinoAnalog3 = A3;
    byte arduinoAnalog4 = A4;
    byte arduinoAnalog5 = A5;

#if BOARD == ARDUINO_UNO || BOARD == ARDUINO_NANO
    byte arduinoDigit5 = 5;
    byte arduinoDigit6 = 6;
    byte arduinoDigit9 = 9;
    byte arduinoDigit10 = 10;
#elif BOARD == NUCLEO_F030R8
    byte arduinoDigit5 = PA5;
    byte arduinoDigit6 = PA6;
    byte arduinoDigit9 = PA9;
    byte arduinoDigit10 = PA10;
#endif

public:
    void initialization(String nameRobot = "default");

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

    void button(bool direction);
    void analog(double threshold);
    void ledSoundOn();
    void ledSoundOff();
    void ledLightOn();
    void ledLightOff();
    void ledGasOn();
    void ledGasOff();
    void pinAnalogOn(byte pin);
    void pinAnalogOff(byte pin);
    void pinDigitalOn(byte pin);
    void pinDigitalOff(byte pin);
    double pinAnalogRead(byte pin);
    bool pinDigitalRead(byte pin);
    void pinAnalogWrite(byte pin, double value);
    void pinDigitalWrite(byte pin, bool value);


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

    double batteryStatus();
    double batteryStatus(byte pin);
    bool batteryStatus(double threshold);
    bool batteryStatus(byte pin, double threshold);

    byte temperature();
    byte temperature(byte pin);
    bool temperature(byte pin, double threshold);
    int humidity();
    int humidity(byte pin);
    bool humidity(byte pin, double threshold);

    bool switchSxFront();
    bool switchDxFront();
    bool switchSxFront(bool invert);
    bool switchDxFront(bool invert);
    bool switchSxRear();
    bool switchDxRear();
    bool switchSxRear(bool invert);
    bool switchDxRear(bool invert);
    bool genericSwitch(byte pin);
    bool genericSwitch(bool invert, byte pin);

    void getVersion();


};

#endif // Ivotek_Robot_H
