#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define soundLimit 500

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);
  double sound = explorer.sound();

  if (soundLimit > sound) {
    explorer.stop();
    explorer.ledSoundOn();
    delay(3000);
    explorer.ledSoundOff();
    explorer.forwards(100, 90);
    delay(1000);
  }
}
