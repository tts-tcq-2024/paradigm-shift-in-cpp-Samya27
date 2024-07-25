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