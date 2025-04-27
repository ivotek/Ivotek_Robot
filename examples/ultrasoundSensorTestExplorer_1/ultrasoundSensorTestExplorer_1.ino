#include <Ivotek_Robot.h>

Ivotek_Robot explorer;

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 100);

  if (explorer.ultrasoundSx(10)) {
    explorer.turnRight(100);
    delay(250);
  }

  if (explorer.ultrasoundDx(10)) {
    explorer.turnLeft(100);
    delay(250);
  }
}
