#include <Ivotek_Robot.h>

Ivotek_Robot explorer;

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 100);

  if (explorer.switchSxFront()) {
    explorer.backwards(100,100);
    delay(500);
    explorer.turnLeft(100);
    delay(250);
  }

  if (explorer.switchDxFront()) {
    explorer.backwards(100,100);
    delay(500);
    explorer.turnRight(100);
    delay(250);
  }
}
