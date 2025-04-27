#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define soundLimit 500

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);

  if (explorer.sound(soundLimit)) {
    explorer.stop();
    explorer.ledSoundOn();
    delay(3000);
    explorer.ledSoundOff();
    explorer.forwards(100, 90);
    delay(1000);
  }
}
