#include <assert.h>
#include <iostream>
#include <string>
#include "PrintMessage.h"
const float CHARGE_RATE_LOWER_LIMIT = (float) NULL;
typedef struct Battery{
const float temperature_p[2];
const float soc_p[2];
const float chargeRate_p[2];
}Battery;

const Battery myBattery = {
    {0,45},
    {20,80},
    {CHARGE_RATE_LOWER_LIMIT, 0.8}};

bool batteryIsOk(float temperature, float soc, float chargeRate) ;
