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
    void forwards(byte speed) override;
    void forwards(byte speedSx, byte speedDx) override;
    void backwards() override;
    void backwards(byte speed) override;
    void backwards(byte speedSx, byte speedDx) override;
    void turnRight() override;
    void turnRight(byte speed) override;

    void turnLeft() override;
    void turnLeft(byte speed) override;
    void turnLeft(byte speedSx,byte speedDx) override;




    void stop() override;
    void getVersion() override;
};

#endif

