#include <Ivotek_Robot.h>

Ivotek_Robot explorer;

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 100);

}
