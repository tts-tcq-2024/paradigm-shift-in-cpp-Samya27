#include <iostream>
#include <string>
#include <map>
#include "PrintMessage.h"

Language PrintLanguage = ENGLISH; 
map<string, string> ErrorMessageEnglish = 
                    {{"Temperature", "Temperature out of range!"}, 
                    {"soc", "State of Charge out of range!"},
                    {"chargeRate", "Charge Rate out of range!"},
                    {"BatteryOK", "Battery status is OK!"},
                    {"BatteryNotOK", "Battery status is not OK!"}};
map<string, string> ErrorMessageGerman = 
                    {{"Temperature", "Temperatur außerhalb des Bereichs!"}, 
                    {"soc", "Ladezustand außerhalb des Bereichs!"},
                    {"chargeRate", "Lade-Rate außerhalb des Bereichs!"},
                    {"BatteryOK", "Batteriezustand ist ok!"},
                    {"BatteryNotOK", "Batteriezustand ist nicht ok!"}};

void printMessage(const Language PrintLanguage, const std::string& key)
{
    if (PrintLanguage == ENGLISH) {
    std:string messageEnglish= ErrorMessageEnglish.find(key);    
    std::cout << messageEnglish << "\n";
    } else if (PrintLanguage == GERMAN) {
        std:string messageGerman= ErrorMessageGerman.find(key);
        std::cout << messageGerman << "\n";
    }
}
