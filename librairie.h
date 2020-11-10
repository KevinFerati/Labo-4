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

#endif //INC_4_LIBRAIRIE_H
