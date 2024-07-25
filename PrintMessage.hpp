#include <iostream>
#include <string>

enum Language { ENGLISH, GERMAN };
Language currentLanguage = ENGLISH;


void printMessage(const std::string& messageEnglish, const std::string& messageGerman);
