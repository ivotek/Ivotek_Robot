#include <Ivotek_Robot.h>

Ivotek_Robot explorer;
#define gasLimit 500

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 90);

  if (explorer.gasAlcool(gasLimit, true)) {
    explorer.stop();
    explorer.ledGasOn();
    delay(3000);
    explorer.ledGasOff();
    explorer.forwards(100, 90);
    delay(3000);
  }
}

