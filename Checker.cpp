#include <assert.h>
#include <iostream>
#include "BatteryStatus.h"

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(55, 65, 1) == false);
  assert(batteryIsOk(35, 95, 0.9) == false);
  assert(batteryIsOk(55, 115, 1) == false);
  assert(batteryIsOk(55, 45, 0.5) == false);
  assert(batteryIsOk(25, 115, 0.7) == false);
  assert(batteryIsOk(40, 75, 1) == false);
}
