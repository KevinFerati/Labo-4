#include <cmath>
#include <cassert>
#include <iostream>
#include "librairie.h"

using namespace std;

const char CHAR_TO_INT_OFFSET = '0';

// Converts the given string to an int.
int strToInt(const string& number) {
   int result = 0;
   int length = number.length() - 1;
   for (char digit : number) {
      assert (isdigit(digit));
      int convertedDigit = digit - CHAR_TO_INT_OFFSET;
      result += pow(10, length--) * convertedDigit;
   }
   return result;
}

bool isEven(int number) {
   return number % 2 == 0;
}

// Returns the sum of the digits in the given string
int sumNumbers(const string& numbers) {
   assert(numbers.length() > 0);

   int sum = 0;

   for (char number : numbers) {
      assert (isdigit(number));
      sum += number - CHAR_TO_INT_OFFSET;
   }

   return sum;
}

// Returns whether the given number is a prime number
bool isPrimeNumber(int number) {
   assert(number > 0);

   bool isPrime = true;
   if (number == 0 || number == 1 ) {
      isPrime = false;
   } else {
      for (int i = 2; i <= number; ++i) {
         if (number % i == 0) {
            isPrime = false;
            break;
         }
      }
   }

   return isPrime;
}

// Return whether the given number is an armstrong number.
bool isArmstrongNumber(const string& number) {
   assert(number.length() > 0);

   int armstrongSum = 0;
   for(char digit : number) {
      assert (isdigit(digit));
      int convertedDigit = digit - CHAR_TO_INT_OFFSET;

      armstrongSum += pow(convertedDigit, 3);

   }

   return strToInt(number) == armstrongSum;
}