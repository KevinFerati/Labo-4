#ifndef INC_4_LIBRAIRIE_H
#define INC_4_LIBRAIRIE_H

#include <string>

enum class Options {
   QUIT,
   IS_EVEN,
   SUM_NUMBERS,
   IS_PRIME_NUMBER,
   IS_ARMSTRONG_NUMBER,
   RANDOM,
   BUFFER,
   TRIGO
};

int strToInt(const std::string& str);

bool isEven(int number);

int sumNumbers(const std::string& numbers);

bool isPrimeNumber(int number);

bool isArmstrongNumber(const std::string& number);

int random(int lower, int upper);

void buffer(char& lowestLowercase, char& highestUppercase, int& length);

void trigo(double angle, double& sine, double& cosine, double& tangent );

bool repondOui(char valueTrue, char valueFalse, std::string question);



#endif //INC_4_LIBRAIRIE_H
