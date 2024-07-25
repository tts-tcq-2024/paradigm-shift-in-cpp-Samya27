#include <assert.h>
#include <iostream>
#include <string>
#include "BatteryStatus.h"
using namespace std;

extern Language PrintLanguage = ENGLISH;
bool IsInRange(const float value,const float *thresholds, const string& key)
{
  int Lowerlimit_index = 0;
  int Upperlimit_index = 1;
  bool indicate_flag = (thresholds[Lowerlimit_index]!= (float) NULL) && ((value<thresholds[Lowerlimit_index]) || (value>thresholds[Upperlimit_index]));
    if(indicate_flag){
      printMessage(PrintLanguage ,key);
      return false;
    }
    if(value>thresholds[Upperlimit_index]){
      printMessage(PrintLanguage ,key);
      return false;
    }
  return true;
}

bool temperatureIsOk(float temperature)
{
  bool status = IsInRange(temperature, myBattery.temperature_p, "Temperature");
  return status;
}
bool socIsOk(float soc)
{
  bool status = IsInRange(soc, myBattery.soc_p, "soc");
  return status;
}
bool chargeRateIsOk(float chargeRate)
{
  bool status = IsInRange(chargeRate, myBattery.chargeRate_p, "chargeRate");
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
