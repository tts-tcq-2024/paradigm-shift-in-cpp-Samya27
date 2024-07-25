#include <assert.h>
#include <iostream>
#include "PrintMessage.hpp"
using namespace std;

bool temperatureIsOk(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    printMessage("Temperature out of range!\n", "Temperatur außerhalb des Bereichs!\n");
    return false;
  }
  return true;
}
bool socIsOk(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printMessage("State of Charge out of range!\n", "Ladezustand außerhalb des Bereichs!\n");
    return false;
  }
  return true;
}
bool chargeRateIsOk(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    printMessage("Charge Rate out of range!\n", "Lade-Rate außerhalb des Bereichs!\n");
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  bool BatteryStatus = temperatureIsOk(temperature)&socIsOk(soc)&chargeRateIsOk(chargeRate);
  if(BatteryStatus)
  {
    printMessage("Battery status is OK!\n", "Batteriezustand ist ok!\n");
  }
  else
  {
    printMessage("Battery status is not OK!\n", "Batteriezustand ist nicht ok!\n");
  }
  return(BatteryStatus);
}
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
