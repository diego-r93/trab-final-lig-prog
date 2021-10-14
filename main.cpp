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

void displayMenu();

int main(int argc, char **argv) {
   PyArray *firstArray, *secondArray;

   FILE *fp;
   string directory = "python-scripts/";
   string filename = "operations.py";
   string path = directory + filename;

   string entry, firstArrayFile, secondArrayFile;
   uint8_t option;

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
            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> firstArrayFile;
            firstArray = new PyArray(firstArrayFile);
            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondArrayFile;
            secondArray = new PyArray(secondArrayFile);
            fp = _Py_fopen("add.py", "r");
            PyRun_SimpleFile(fp, "add.py");
            break;

         case 2:
            break;

         case 3:
            break;

         case 4:
            break;

         case 5:         
            fp = _Py_fopen(path.c_str(), "r");
            PyRun_SimpleFile(fp, path.c_str());
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

void displayMenu() {
   cout << "\n\n------------------- MENU ------------------------" << endl;
   cout << "1 - Somar duas Matrizes" << endl;
   cout << "2 - Subtrair duas Matrizes" << endl;
   cout << "3 - Multiplicar duas Matrizes" << endl;
   cout << "4 - Inversa de uma Matriz Quadrada" << endl;
   cout << "5 - Determinante de uma Matriz Quadrada" << endl;
   cout << "6 - Transposta de uma Matriz" << endl;
   cout << "7 - Gráfico de uma função" << endl;
   cout << "8 - Sair" << endl;
   cout << "-------------------------------------------------" << endl;
   cout << ">>> ";
}