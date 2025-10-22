#ifndef EXPLORER_ROBOT_H
#define EXPLORER_ROBOT_H

#include "RobotStrategy.h"
#include "../Config/RobotPins.h"

class ExplorerRobot : public RobotStrategy {
private:
    RobotPins pins;

public:
    ExplorerRobot(); // Costruttore

    void initialize() override;
    void forwards() override;
    void backwards() override;
    void turnLeft() override;
    void turnRight() override;
    void stop() override;
    void getVersion() override;
};

#endif

