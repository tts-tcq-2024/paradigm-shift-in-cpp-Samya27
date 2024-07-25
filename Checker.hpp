#include <assert.h>
#include <iostream>
#include "Message.hpp"

const float TEMPERATURE_LOWER_LIMIT = 0;
const float SOC_LOWER_LIMIT = 20;
const float CHARGE_RATE_LOWER_LIMIT = 0;

const float TEMPERATURE_UPPER_LIMIT = 45.0;
const float SOC_UPPER_LIMIT = 80.0;
const float CHARGE_RATE_UPPER_LIMIT = 0.8;

const float WARNING_TOLERANCE_PERCENTAGE = 0.05;  // 5% tolerance for warnings

bool temperatureIsOk(float temperature);
bool socIsOk(float soc);
bool chargeRateIsOk(float chargeRate);
