#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define luxDx 1

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);

  double objectSx = explorer.ultrasoundSx();
  double objectDx = explorer.ultrasoundDx();

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

  if (explorer.lightDx(luxDx)) {
    explorer.stop();
    explorer.ledLightOn();
    delay(3000);
    explorer.ledLightOff();
    explorer.forwards(100, 90);
    delay(1000);
  }
}
