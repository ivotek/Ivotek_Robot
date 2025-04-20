#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define luxDx 2

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);

  double objectSx = explorer.ultrasoundSx();
  double objectDx = explorer.ultrasoundDx();
  double lightDx = explorer.lightDx();

  if (explorer.ultrasoundSx(10)) {
    explorer.turnRight(100);
    delay(250);
  }

  if (explorer.ultrasoundDx(10)) {
    explorer.turnLeft(100);
    delay(250);
  }

  //double lightSx = explorer.lightDx();
  //double lightDx = explorer.lightSx();
  //double lightCx = explorer.lightCx();

  if (lightDx < luxDx) {
    explorer.stop();
    explorer.ledLightOn();
    delay(3000);
    explorer.ledLightOff();
    explorer.forwards(100, 90);
    delay(1000);
  }
}
