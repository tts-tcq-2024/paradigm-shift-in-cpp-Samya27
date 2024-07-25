#include <assert.h>
#include <iostream>
#include <string>
#include "PrintMessage.h"

extern Language PrintLanguage;
const float CHARGE_RATE_LOWER_LIMIT = (float) NULL;
bool batteryIsOk(float temperature, float soc, float chargeRate) ;
