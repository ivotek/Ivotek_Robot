#include "Ivotek_Robot.h"

Ivotek_Robot explorer;

void setup() {
  explorer.initialization();
}

void loop() {
  explorer.getVersion();
}
