#include <Arduino.h>
#include "ExplorerRobot.h"
#include "../Config/RobotInfo.h"

ExplorerRobot::ExplorerRobot() {
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

void ExplorerRobot::initialize() {
    pinMode(pins.arduinoDigit5, OUTPUT);
    pinMode(pins.arduinoDigit6, OUTPUT);
    pinMode(pins.arduinoDigit9, OUTPUT);
    pinMode(pins.arduinoDigit10, OUTPUT);
}

void ExplorerRobot::forwards() {
    analogWrite(pins.arduinoDigit5, 255);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 255);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::backwards() {
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 255);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 255);
}

void ExplorerRobot::turnLeft() {
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 255);
    analogWrite(pins.arduinoDigit9, 255);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::turnRight() {
    analogWrite(pins.arduinoDigit5, 255);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 255);
}

void ExplorerRobot::stop() {
    analogWrite(pins.arduinoDigit5, 0);
    analogWrite(pins.arduinoDigit6, 0);
    analogWrite(pins.arduinoDigit9, 0);
    analogWrite(pins.arduinoDigit10, 0);
}

void ExplorerRobot::getVersion(){
    Serial.print("Robot: ");
    Serial.print(RobotInfo::getRobotName());
    Serial.print(" -- Version: ");
    Serial.println(RobotInfo::getVersion());
}

