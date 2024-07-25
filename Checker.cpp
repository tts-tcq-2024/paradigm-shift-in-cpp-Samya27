#include <assert.h>
#include <iostream>
#include <string>
#include "Checker.h"
using namespace std;

bool IsInRange(float value, float UpperLimit, float Lowerlimit, const string& key)
{
  //if(Lowerlimit!= (float) NULL){
    if((Lowerlimit!= (float) NULL) && ((value<Lowerlimit) && (value>UpperLimit))){
      printMessage(PrintLanguage ,key);
      return false;
    }
  //}
  //else{
    else if(value>UpperLimit){
      printMessage(PrintLanguage ,key);
      return false;
    }
  //}
  return true;
}

bool temperatureIsOk(float temperature)
{
  bool status = IsInRange(temperature, 45, 0, "Temperature");
  // if(temperature < 0 || temperature > 45) 
  // {
  //   printMessage("Temperature out of range!\n", "Temperatur außerhalb des Bereichs!\n");
  //   return false;
  // }
  return status;
}
bool socIsOk(float soc)
{
  bool status = IsInRange(soc, 80, 20, "soc");
  // if(soc < 20 || soc > 80) 
  // {
  //   printMessage("State of Charge out of range!\n", "Ladezustand außerhalb des Bereichs!\n");
  //   return false;
  // }
  return status;
}
bool chargeRateIsOk(float chargeRate)
{
  bool status = IsInRange(chargeRate, 0.8, CHARGE_RATE_LOWER_LIMIT, "chargeRate");
  // if(chargeRate > 0.8) 
  // {
  //   printMessage("Charge Rate out of range!\n", "Lade-Rate außerhalb des Bereichs!\n");
  //   return false;
  // }
  return status;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  bool BatteryStatus = temperatureIsOk(temperature)&socIsOk(soc)&chargeRateIsOk(chargeRate);
  if(BatteryStatus)
  {
    printMessage(PrintLanguage ,"BatteryOK");
  }
  else
  {
    printMessage(PrintLanguage ,"BatteryNotOK");
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
