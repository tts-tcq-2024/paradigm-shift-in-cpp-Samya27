#include <iostream>
#include <string>
#include "Checker.hpp"

enum Language { ENGLISH, GERMAN };
Language currentLanguage = ENGLISH;


void printMessage(const std::string& messageEnglish, const std::string& messageGerman);
void printWarningIfNeeded(float value, float upperLimit, float lowerLimit, const std::string& messageApproachPeak, const std::string& messageApproachlow);
