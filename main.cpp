// Trabalho 3 de Linguagens de Programação
// Autores: Diego Rodrigues da Silva
//          Raiano Raiano Martins
// Compilador Utilizado: g++ 9.3.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "pyClass.h"
#include "consts.h"

using namespace std;

void displayMenu();

bool checkOption(uint8_t);

int main(int argc, char **argv) {
   if (argc != ARGUMENTS_SIZE) {
      cout << "Invalid number of arguments." << endl;
      cout << "Use: " << argv[0] << " <OPTION>" << endl;
      exit(INVALID_ARGUMENTS_SIZE);
   }

   string input(argv[1]);   
   uint16_t option = atoi(argv[1]);

   if (input.length() > 1) {
      cout << "Invalid argument size." << endl;
      cout << "Use: " << argv[0] << " <DIGIT>" << endl;
      exit(INVALID_ARGUMENT_SIZE);
   }
   else if (any_of(input.begin(), input.end(), [](char ch) { return !isdigit(ch); })) {
      cout << "Invalid argument type." << endl;
      cout << "Use: " << argv[0] << " <DIGIT>" << endl;
      exit(INVALID_ARGUMENT); 
   }   
   else if (!checkOption(option)) {
      cout << "Invalid option." << endl;
      cout << "Valid options: 1, 2, 3, 4, 5, 6" << endl;
      cout << "Read the file README to understand the menu." << endl;
      exit(INVALID_OPTION);      
   } 
   
   string entry;

   switch (option) {
         case 1:
            break;

         case 2:            
            break;

         case 3:
            break;

         case 4:
            break;

         case 5:
            break;

         case 6:
            break;
   }

   return OKAY;
}

inline bool checkOption(uint8_t option)
{
   return (option >= 1 && option <= 6) ? true: false;
}

void displayMenu() {
   cout << "\n\n------------------- MENU ------------------------" << endl;
   cout << "1 - Inserir paciente" << endl;
   cout << "2 - Buscar paciente" << endl;
   cout << "3 - Exibir pacientes cadastrados" << endl;      
   cout << "4 - Sair" << endl;
   cout << "-------------------------------------------------" << endl;
   cout << ">>> ";
}