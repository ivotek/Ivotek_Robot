#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

#include <Arduino.h>

namespace RobotInfo {
    inline const String VERSION = "2.0.0";
    inline String robotName = "DEFAULT";
    inline String boardName = "DEFAULT";
    inline double voltageMCU = 5.0;
    inline int numADconvertArduinoUno = 1024;
    inline byte ANALOG_MIN = 0;
    inline byte ANALOG_MAX = 255;


    inline void setRobotName(const String& name) { robotName = name; }
    inline const String& getRobotName() { return robotName; }

    inline void setBoardName(const String& name) { boardName = name; }
    inline const String& getBoardName() { return boardName; }

    inline const String& getVersion() { return VERSION; }

    inline double setVoltageMCU(const double& voltage) {voltageMCU = voltage; }
    inline const double& getVoltageMCU() { return voltageMCU; }

    inline double setNumADconvertArduinoUno(const int& number) {numADconvertArduinoUno = number; }
    inline const int& getNumADconvertArduinoUno() { return numADconvertArduinoUno; }
}

#endif

