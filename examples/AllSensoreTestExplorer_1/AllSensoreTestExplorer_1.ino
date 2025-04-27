#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define luxDx 2
#define soundLimit 500
#define gasLimit 500

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);

  if (explorer.ultrasoundSx(10)) {
    explorer.turnRight(100);
    delay(250);
  }

  if (explorer.ultrasoundDx(10)) {
    explorer.turnLeft(100);
    delay(250);
  }

  if (explorer.lightDx(luxDx)) {
    explorer.stop();
    explorer.ledLightOn();
    delay(3000);
    explorer.ledLightOff();
    explorer.forwards(100, 90);
    delay(1000);
  }

  if (explorer.sound(soundLimit)) {
    explorer.stop();
    explorer.ledSoundOn();
    delay(3000);
    explorer.ledSoundOff();
    explorer.forwards(100, 90);
    delay(1000);
  }

  if (explorer.gasAlcool(gasLimit, true)) {
    explorer.stop();
    explorer.ledGasOn();
    delay(3000);
    explorer.ledGasOff();
    explorer.forwards(100, 90);
    delay(3000);
  }
}

