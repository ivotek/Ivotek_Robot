#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

#include <Arduino.h>

namespace RobotInfo {
    inline const String VERSION = "2.0.0";
    inline String robotName = "DEFAULT";
    inline String boardName = "DEFAULT";

    inline void setRobotName(const String& name) { robotName = name; }
    inline const String& getRobotName() { return robotName; }

    inline void setBoardName(const String& name) { boardName = name; }
    inline const String& getBoardName() { return boardName; }
    
    inline const String& getVersion() { return VERSION; }
}

#endif

