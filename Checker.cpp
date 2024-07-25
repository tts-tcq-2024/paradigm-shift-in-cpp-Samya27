#include <assert.h>
#include <iostream>
#include "Message.hpp"
#include "Checker.hpp"
using namespace std;


bool temperatureIsOk(float temperature) 
{
  if (temperature < TEMPERATURE_LOWER_LIMIT || temperature > TEMPERATURE_UPPER_LIMIT)
  {
    printMessage("Temperature out of range!\n", "Temperatur außerhalb des Bereichs!\n");
    return false;
  }
  printWarningIfNeeded(temperature, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_LOWER_LIMIT, "Warning: Approaching Temperature Peak", NULL);
  return true;
}

bool socIsOk(float soc) 
{
  if (soc < CHARGE_RATE_LOWER_LIMIT || soc > SOC_UPPER_LIMIT) 
  {
    printMessage("State of Charge out of range!\n", "Ladezustand außerhalb des Bereichs!\n");
    return false;
  }
  printWarningIfNeeded(soc, SOC_UPPER_LIMIT, SOC_LOWER_LIMIT, "Warning: Approaching charge-peak", "Warning: Approaching discharge");
  return true;
}

bool chargeRateIsOk(float chargeRate) 
{
  if (chargeRate > CHARGE_RATE_UPPER_LIMIT) 
  {
    printMessage("Charge Rate out of range!\n", "Lade-Rate außerhalb des Bereichs!\n");
    return false;
  }
  printWarningIfNeeded(chargeRate, CHARGE_RATE_UPPER_LIMIT, CHARGE_RATE_LOWER_LIMIT,  "Warning: Approaching charge rate -peak", NULL);
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return(temperatureIsOk(temperature)&socIsOk(soc)&chargeRateIsOk(chargeRate));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
