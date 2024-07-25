#include <iostream>
#include <string>

enum Language { ENGLISH, GERMAN };
enum Language PrintLanguage = ENGLISH; 

void printMessage(const Language PrintLanguage, const std::string& key);
