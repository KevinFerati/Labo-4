#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include <iomanip>
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

   int sum = 0;

   for (char number : numbers) {
      if (isdigit(number)) {
         sum += number - CHAR_TO_INT_OFFSET;
      }
   }

   return sum;
}

// Returns whether the given number is a prime number
bool isPrimeNumber(int number) {
   if (number == 0 || number == 1 ) {
      return false;
   }

   for (int i = 2; i <= number / 2; ++i) {
      if (number % i == 0) {
         return false;
      }
   }

   return true;
}

// Return whether the given number is an armstrong number.
bool isArmstrongNumber(const string& number) {

   int armstrongSum = 0;
   for(char digit : number) {
      if (!isdigit(digit)) {
         return false;
      }

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
   }

   if(number2 < number1){
      return rand() % (number1 - number2 + 1) + number2;
   }

   // if two are the same number, return this number
   return number2;
}

// Returns the lowest Lowercase letter, Highest Uppercase letter & length of the content in buffer
void analyzeBuffer(string& buffer, char& lowestLowercase, char& highestUppercase, int& length) {
   const char MAX_UPPER = 'Z',
              MIN_UPPER = 'A';

   const int MAX_LOWER = 'z',
             MIN_LOWER = 'a';

   const int LOWER_INIT = MAX_LOWER + 1;

   lowestLowercase = LOWER_INIT; // High value to ensure we go down
   highestUppercase = 0;
   length = 0;

   // loop through the string
   for(char& c : buffer){
      // Uppercase filter
      if (c <= MAX_UPPER && c >= MIN_UPPER){
         if (c > highestUppercase){
            highestUppercase = c;
         }
      }
      // Lowercase filter 1
      else if (c <= MAX_LOWER && c >= MIN_LOWER){
         if (c < lowestLowercase){
            lowestLowercase = c;
         }
      }
      // and we keep count for each iterations
      length++;
   }
   //if no lowercase were found, we put lowestLowerCase to O, making it null
   lowestLowercase = lowestLowercase >= LOWER_INIT ? 0 : lowestLowercase;
}


// Returns the sine, cosine, tangent of a given angle
void trigo(double angle, double& sine, double& cosine, double& tangent ) {
   double radian = angle *  M_PI / 180;
   sine = sin(radian);
   cosine = cos(radian);
   tangent = tan(radian);
}


// Ask the user for a char and returns whether its value true
bool answerYes(char valueTrue, char valueFalse, const string& question) {

   while (true){
      cout << question << " [ " << valueTrue << " - " << valueFalse << " ] : ";
      char answer;
      cin >> answer;
      answer = toupper(answer);

      if (toupper(answer) == toupper(valueTrue)){
         return true;
      } else if (toupper(answer) == toupper(valueFalse)){
         return false;
      }
   }
}

// Asks the user for an integer and repeat while the cin failed or the number is
// lesser than minValue or greater than maxValue
int askUserForInt(const string& message, int minValue, int maxValue) {
   const string CIN_FAIL_MESSAGE = "Mauvais format de réponse";
   const string NOT_IN_RANGE = "La valeur n'est pas dans les limites demandees";
   const int VALUE_WIDTH = 6,
             MESSAGE_WIDTH = 8;

   int number;
   while (true) {

      cout << right << setw(MESSAGE_WIDTH) << message
           << setw(VALUE_WIDTH) << "[" << minValue << " - " << maxValue << "] :";

      cin >> number;

      if (cin.fail()) {
         cout << endl << CIN_FAIL_MESSAGE << endl;
         continue;
      }

      CLEAR_BUFFER;
      cin.clear();

      if (number < minValue || number > maxValue) {
         cout << endl << NOT_IN_RANGE << endl;
         continue;
      }
      return number;
   }
}