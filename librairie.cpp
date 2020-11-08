#include <cmath>
#include <assert.h>
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
   for(char digit : number) {
      assert (isdigit(number));
      armstrongSum += pow(digit, 3);
   }
   // TODO: No usage of std::stoid()
   return std::stoi(number) == armstrongSum;
}