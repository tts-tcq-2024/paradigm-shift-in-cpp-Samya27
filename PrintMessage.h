#include <iostream>
#include <string>

enum Language { ENGLISH, GERMAN };
enum Language PrintLanguage = ENGLISH; 

void printMessage(const Language Print_Language, const std::string& key);
