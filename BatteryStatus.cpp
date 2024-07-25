#include <assert.h>
#include <iostream>
#include <string>
#include "BatteryStatus.h"
using namespace std;
#define Lowerlimit_index 0;
#define Upperlimit_index 1;

extern Language PrintLanguage = ENGLISH;
bool IsInRange(float value, float *thresholds, const string& key)
{
  bool indicate_flag = (thresholds[Lowerlimit_index]!= (float) NULL) && ((value<thresholds[Lowerlimit_index]) || (value>thresholds[Upperlimit_index]));
    if(indicate_flag){
      printMessage(PrintLanguage ,key);
      return false;
    }
    if(value>UpperLimit){
      printMessage(PrintLanguage ,key);
      return false;
    }
  return true;
}

bool temperatureIsOk(float temperature)
{
  bool status = IsInRange(temperature, Battery.temperature_p, "Temperature");
  return status;
}
bool socIsOk(float soc)
{
  bool status = IsInRange(soc, Battery.soc_p, "soc");
  return status;
}
bool chargeRateIsOk(float chargeRate)
{
  bool status = IsInRange(chargeRate, Battery.chargeRate_p, "chargeRate");
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
