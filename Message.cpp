#include <iostream>
#include <string>
#include "Message.hpp"

void printMessage(const std::string& messageEnglish, const std::string& messageGerman)
{
    if (currentLanguage == ENGLISH) {
    std::cout << messageEnglish << "\n";
    } else if (currentLanguage == GERMAN) {
        std::cout << messageGerman << "\n";
    }
}

void printWarningIfNeeded(float value, float upperLimit, float lowerLimit, const std::string& messageApproachPeak, const std::string& messageApproachlow) 
{
    float UpperWarningThreshold = upperLimit - (upperLimit * WARNING_TOLERANCE_PERCENTAGE);
    float LowerWarningThreshold = lowerLimit + (lowerLimit * WARNING_TOLERANCE_PERCENTAGE);
    bool approachingPeak = (value >= UpperWarningThreshold);
    bool approachingLow = (value <= LowerWarningThreshold && LowerWarningThreshold != 0);

    if (approachingPeak) {
        printMessage( messageApproachPeak,"Warnung: Annäherung an den Spitzenwert\n");
    }
    else if (approachingLow){
        printMessage( messageApproachlow , "Warnung: Annäherung an die Entlade-Spitze\n");
    }
}
