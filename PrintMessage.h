#include <iostream>
#include <string>

enum Language { ENGLISH, GERMAN };
enum Language PrintLanguage = ENGLISH; 

void printMessage(const std::string& messageEnglish, const std::string& messageGerman);
