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

void printOption(Options option, string message, int width);

int main() {
   const int MIN_VALUE =    0,
             MAX_VALUE = 1000;

   const int RANDOM_MIN_VALUE = -100,
             RANDOM_MAX_VALUE =  100;

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
            break;

         case Options::SUM_NUMBERS :
            break;

         case Options::IS_PRIME_NUMBER :
            break;

         case Options::IS_ARMSTRONG_NUMBER :
            break;

         case Options::RANDOM :
            break;

         case Options::BUFFER :
            break;

         case Options::TRIGO :
            break;

         default:
            cout << endl << "Option non disponible" << endl;
            continue;
      }

   } while(true);

   return 0;
}

void printOption(Options option, string message, int width) {
   cout << right << setw(width)
        << (int) option << " " << message << endl;
}