/*
  ---------------------------------------------------------------------------
  Fichier     : <fichier>.cpp
  Nom du labo : Labo 4 - Librairie
  Auteur(s)   : Kevin Ferati, Aurélien Richard
  Date        : 05.11.2020
  But         : Le programme affiche un certain nombre d'options pour une librairie
                qui une fois sélectionné, exécute certaines tâches.
                Les fonctionnalités disponibles sont :
                - Détermine si un nombre donné par l'utilisateur est pair ou impair
                - Demande une liste de nombres à un utilisateur et affiche la somme
                - Détermine si un numéro est premier
                - Détermine si un numéro est un nombre d'armstrong
                - Affiche une valeur aléatoire dans une intervalle
                - Traite le buffer et affiche le nombre de caractères et la plus petite
                  et la plus grande lettre
                - Affiche selon une valeur donnéepar l'utilisateur le sinus, cosinus et
                  tangente



  Remarque(s) : à compléter

  Compilateur : MinGW-64
  ---------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include "librairie.h"

using namespace std;

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

void printOption(const Options& option, const string& message, int width);


int main() {
   const int MIN_VALUE =    0,
             MAX_VALUE = 1000;

   const int RANDOM_MIN_VALUE = -100,
             RANDOM_MAX_VALUE =  100;

   const int MAX_ANGLE = 360,
             MIN_ANGLE = 0;

   const int OPTIONS_WIDTH = 12;

   cout << "Bonjour" << endl
        << "Ce programme vous laisse choisir plusieurs options" << endl;

   cout << "Options" << endl;

   printOption(Options::IS_EVEN, "est pair", OPTIONS_WIDTH);
   printOption(Options::SUM_NUMBERS, "somme chiffres", OPTIONS_WIDTH);
   printOption(Options::IS_PRIME_NUMBER, "nombre 1er", OPTIONS_WIDTH);
   printOption(Options::IS_ARMSTRONG_NUMBER, "nombre de Armstrong", OPTIONS_WIDTH);
   printOption(Options::RANDOM, "nombre aleatoire", OPTIONS_WIDTH);
   printOption(Options::BUFFER, "buffer", OPTIONS_WIDTH);
   printOption(Options::TRIGO, "trigo", OPTIONS_WIDTH);
   printOption(Options::QUIT, "quitter", OPTIONS_WIDTH);

   do {
      cout << "votre choix : ["
           << (int) Options::QUIT << " - " << (int) Options::TRIGO << "] : ";
      int optionsChoice;
      cin >> optionsChoice;
      if (cin.fail()) {
         cout << endl << "Mauvais format de réponse" << endl;
         continue;
      }

      cin.clear();
      CLEAR_BUFFER;

      switch ((Options)optionsChoice) {
         case Options::IS_EVEN :
            int number;
            cout << "entrer une valeur : [" << MIN_VALUE << " - "<<MAX_VALUE<<"] : ";
            cin>>number;
            if (isEven(number)){
               cout << number << " est une valeur pair" << endl;
            }else{
               cout << number << " est une valeur impair" << endl;
            }
            break;

         case Options::SUM_NUMBERS :{
            string numbers;
            cout << "entrer une valeur : [" << MIN_VALUE << " - "<<MAX_VALUE<<"] : ";
            cin>>numbers;
            cout << "la somme des chiffres " << numbers << " = " << sumNumbers(numbers) << endl;
         }
            break;

         /// DOES NOT WORK
         // WHEN GIVEN 7, IT SHOULD RETURN TRUE
         // ALSO, WHEN GIVING 0 TO start WE GET AN ERROR
         case Options::IS_PRIME_NUMBER :
            int start, finish;
            cout << "Determiner le snombres premiers compris dans un intervalle" << endl;
            cout << "- debut : [" << MIN_VALUE << " - "<<MAX_VALUE<<"] : ";
            cin >> start;
            cout << "- fin : [20 - "<<MAX_VALUE<<"] : ";
            cin >> finish;
            for (int number = start; number < finish ; number++) {
               if(isPrimeNumber(7)){
                  cout << "le nombre " << number << " est un nombre premier" << endl;
               }
               cout << number;
            }



            break;

         case Options::IS_ARMSTRONG_NUMBER :
         {
            int start, finish;
            cout << "Determiner les nombres premiers compris dans un intervalle" << endl;
            cout << "- debut : [" << MIN_VALUE << " - "<<MAX_VALUE<<"] : ";
            cin >> start;
            cout << "- fin : [20 - "<<MAX_VALUE<<"] : ";
            cin >> finish;
            for (int number = start; number < finish ; number++) {
               if(isArmstrongNumber(to_string(number))){
                  cout << "le nombre " << number << " est un nombre de Armstrong" << endl;
               }
            }
         }
            break;

         case Options::RANDOM :
         {
            int min, max, number;
            cout << "- min : [" << RANDOM_MIN_VALUE << " - "<< RANDOM_MAX_VALUE <<"] : ";
            cin >> min;
            cout << "- max : ["<< RANDOM_MIN_VALUE << " - "<< RANDOM_MAX_VALUE <<"] : ";
            cin >> max;
            cout << "- nbre : [" << MIN_VALUE << "- "<< RANDOM_MAX_VALUE <<"] : ";
            cin >> number;

            cout << "voici des valeurs aleatoires [" << min << " - " << max << "] : " << endl;

            for (int i = 0; i < number ; i++) {
               cout << random(min, max);
               if (i != number - 1) {
                  cout << ", ";
               }
            }
            cout << endl << endl;
         }
            break;

         case Options::BUFFER : {
            string phrase;
            char lowestLowerCase, higherUpperCase;
            int length;
            cout << "entrer une phrase : ";
            // we get everything the user enters
            getline(cin, phrase);
            buffer(phrase, lowestLowerCase, higherUpperCase, length);
            if (lowestLowerCase)
               cout << "la plus petit minuscule : " << lowestLowerCase << endl;
            if (higherUpperCase)
               cout << "la plus grande majuscule : " << higherUpperCase << endl;
            cout << "le nbre de caracteres : " << length << endl << endl;
         }
            break;

         case Options::TRIGO :
            double angle, sine, cosine, tangent;
            cout << "entrer un angle en degre : [" << MIN_ANGLE << " - " << MAX_ANGLE << "] : ";

            cin>>angle;
            trigo(angle, sine, cosine, tangent);
            cout << "sin("<< angle << ") = " << sine << endl
                  << "cos("<< angle << ") = " << cosine << endl
                  << "tan("<< angle << ") = " << tangent << endl;

            break;
         case Options::QUIT :
            if (repondOui('o', 'n', "Souhaitez-vous quitter l'appplication ?")){
               return EXIT_SUCCESS;
            }
            break;
         default:
            cout << endl << "Option non disponible" << endl;
            continue;
      }

   } while(true);

   return EXIT_SUCCESS;
}

void printOption(const Options& option, const string& message, int width) {
   cout << right << setw(width)
        << (int) option << " " << message << endl;
}