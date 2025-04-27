#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define luxDx 0.15

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);
  delay(1000);
  explorer.turnLeft();
  delay(1000);
  explorer.turnRight();
  delay(1000);
  explorer.backwards();
  delay(1000);
}
