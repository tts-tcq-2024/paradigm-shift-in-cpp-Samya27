#include <assert.h>
#include <iostream>
#include <string>
#include "BatteryStatus.h"
using namespace std;

extern Language PrintLanguage = ENGLISH;
bool islessthan(float value, float UpperLimit, const string& key)
{
    if(value>UpperLimit){
      printMessage(PrintLanguage ,key);
      return false;
    }
  return true;
}
bool IsInRange(float value, float UpperLimit, float Lowerlimit, const string& key)
{
  if((value<Lowerlimit) || (value>UpperLimit)){
    printMessage(PrintLanguage ,key);
    return false;
  }
  return true;
}

bool temperatureIsOk(float temperature)
{
  bool status = IsInRange(temperature, 45, 0, "Temperature");
  return status;
}
bool socIsOk(float soc)
{
  bool status = IsInRange(soc, 80, 20, "soc");
  return status;
}
bool chargeRateIsOk(float chargeRate)
{
  bool status = islessthan(chargeRate, 0.8, "chargeRate");
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
