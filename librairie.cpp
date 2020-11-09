#include <cmath>
#include <assert.h>
#include <iostream>
#include "librairie.h"

using namespace std;

bool isEven(int number) {
   return number % 2 == 0;
}

int sumNumbers(string numbers) {
   int sum = 0;

   for (char number : numbers) {
      assert (isdigit(number));
      sum += number;
   }

   return sum;
}

bool isPrimeNumber(int number) {
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

bool isArmstrongNumber(string number) {
   int armstrongSum = 0;
   int convertedNumber = 0;
   int length = number.length() - 1;

   for(char digit : number) {
      assert (isdigit(digit));
      int convertedDigit = digit - '0';

      armstrongSum += pow(convertedDigit, 3);

      convertedNumber += pow(10, length--) * convertedDigit;
   }

   return convertedNumber == armstrongSum;
}