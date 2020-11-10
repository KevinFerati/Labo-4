#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
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

// Returns a random integer between 2 given numbers
int random(int number1, int number2){
   // we need to find the lowest number and adapt the rand if that's the case
   if (number1 < number2){
      return rand() % (number2 - number1 + 1) + number1;
   }else if(number2 < number1){
      return rand() % (number1 - number2 + 1) + number2;
   }else{ // if two are the same number, return this number
      return number2;
   }
}

// Returns the lowest Lowercase letter, HIghest Uppercase letter & length of the content in buffer
void buffer(char& lowestLowercase, char& highestUppercase, int& length){
   string buffer;
   lowestLowercase = 255; // High value to ensure we go down
   highestUppercase = 0;
   length = 0;

   // we get everything the user enters
   getline(cin, buffer);

   // loop through the string
   for(char& c : buffer){
      // Uppercase filter 90 = Z, 65 = A
      if (int(c) <= 90 && int(c)>= 65){
         if (int(c)> int(highestUppercase)){
            highestUppercase = c;
         }
      }
         // Lowercase filter 122 = z, 97 = a
      else if (int(c) <= 122 && int(c)>= 97){
         if (int(c)< int(lowestLowercase)){
            lowestLowercase = c;
         }
      }
      // and we keep count for each iterations
      length++;
   }
   //if no lowercase were found, we put lowestLowerCase to O, making it null
   lowestLowercase = lowestLowercase == 255 ? 0 : lowestLowercase;
}


// Returns the sine, cosine, tangent of a given angle
void trigo(double angle, double& sine, double& cosine, double& tangent ){
   double radian = angle*M_PI/180;
   sine = sin(radian);
   cosine = cos(radian);
   tangent = tan(radian);
}


// returns true of false depending of the user answe to the given question
bool repondOui(char valueTrue, char valueFalse, string question){

   while (true){
      cout << question << " [ " << valueTrue << " - " << valueFalse << " ] : ";
      char answer;
      cin >> answer;

      if (toupper(answer) == toupper(valueTrue)){
         return true;
      }else if (toupper(answer) == toupper(valueFalse)){
         return false;
      }
   }
}