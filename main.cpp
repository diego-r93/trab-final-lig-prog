// Trabalho Final de Linguagens de Programação
// Autores: Diego Rodrigues da Silva
//          Raiano Raiano Martins
// Compiladores Utilizados: g++ 9.3.0
//                          clang++ 10.0.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "consts.h"
#include "pyClass.h"

using namespace std;

int main() {
   string entry;
   uint8_t option;

   int py_argc = 3;
   char *py_argv[py_argc];

   string firstEntry, secondEntry;

   CPyInstance CPyObject;

   do {
      displayMenu();
      cin >> entry;
      string input(entry);

      if (any_of(input.begin(), input.end(), [](char ch) { return !isdigit(ch); })) {
         cout << "Invalid option." << endl;
         cout << "Valid options: [1 ... 8]" << endl;
         cout << "Read the file README to understand the menu." << endl;
         continue;
      } else {
         option = stoi(entry);
      }

      switch (option) {
         case 1:
            py_argv[0] = (char *)"add.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            py_argv[1] = (char *)firstEntry.c_str();

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            py_argv[2] = (char *)secondEntry.c_str();

            runPyScriptArgs(py_argv[0], py_argc, py_argv);
            break;

         case 2:
            py_argv[0] = (char *)"sub.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            py_argv[1] = (char *)firstEntry.c_str();

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            py_argv[2] = (char *)secondEntry.c_str();

            runPyScriptArgs(py_argv[0], py_argc, py_argv);
            break;

         case 3:
            py_argv[0] = (char *)"mult.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            py_argv[1] = (char *)firstEntry.c_str();

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            py_argv[2] = (char *)secondEntry.c_str();

            runPyScriptArgs(py_argv[0], py_argc, py_argv);
            break;

         case 4:
            break;

         case 5:
            break;

         case 6:
            break;

         case 7:
            break;

         case 8:
            break;

         default:
            cout << "Invalid option." << endl;
            cout << "Valid options: [1 ... 8]" << endl;
            cout << "Read the file README to understand the menu." << endl;
            cin.ignore();
      }
   } while (option != 8);

   return OKAY;
}