// Trabalho Final de Linguagens de Programação
// Autores: Diego Rodrigues da Silva
//          Raiano Raiano Martins
// Compiladores Utilizados: g++ 9.3.0
//                          clang++ 10.0.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "consts.h"
#include "functions.h"
#include "pyClass.h"

using namespace std;

int main() {
   string entry;
   uint8_t option;

   int py_argc = 3;
   char *py_argv[py_argc];

   string firstEntry, secondEntry;

   PyArray *matriz_1, *matriz_2, *resultado;
   PyFunction *function;

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
            remove("result.txt");
            py_argv[0] = (char *)"add.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Primeira Matriz:" << endl;
            printVector(matriz_1->getMatriz());

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            matriz_2 = new PyArray(secondEntry);
            py_argv[2] = (char *)matriz_2->getFilename().c_str();
            cout << "Segunda Matriz:" << endl;
            printVector(matriz_2->getMatriz());

            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Resultado da soma:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 2:
            remove("result.txt");
            py_argv[0] = (char *)"sub.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Primeira Matriz:" << endl;
            printVector(matriz_1->getMatriz());

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            matriz_2 = new PyArray(secondEntry);
            py_argv[2] = (char *)matriz_2->getFilename().c_str();
            cout << "Segunda Matriz:" << endl;
            printVector(matriz_2->getMatriz());

            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Resultado da subtração:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 3:
            remove("result.txt");
            py_argv[0] = (char *)"mult.py";

            cout << "Digite o nome do arquivo da primeira matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Primeira Matriz:" << endl;
            printVector(matriz_1->getMatriz());

            cout << "Digite o nome do arquivo da segunda matriz: " << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> secondEntry;
            matriz_2 = new PyArray(secondEntry);
            py_argv[2] = (char *)matriz_2->getFilename().c_str();
            cout << "Segunda Matriz:" << endl;
            printVector(matriz_2->getMatriz());

            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Resultado da multiplicação:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 4:
            remove("result.txt");
            py_argv[0] = (char *)"inv.py";

            cout << "Digite o nome do arquivo da matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Matriz Escolhida:" << endl;
            printVector(matriz_1->getMatriz());           

            py_argv[2] = (char *)" ";
            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Matriz inversa:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 5:
            remove("result.txt");
            py_argv[0] = (char *)"det.py";

            cout << "Digite o nome do arquivo da matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Matriz Escolhida:" << endl;
            printVector(matriz_1->getMatriz());           

            py_argv[2] = (char *)" ";
            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Determinante:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 6:
            remove("result.txt");
            py_argv[0] = (char *)"transp.py";

            cout << "Digite o nome do arquivo da matriz: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            matriz_1 = new PyArray(firstEntry);
            py_argv[1] = (char *)matriz_1->getFilename().c_str();
            cout << "Matriz Escolhida:" << endl;
            printVector(matriz_1->getMatriz());           

            py_argv[2] = (char *)" ";
            runPyScriptArgs(py_argv[0], py_argc, py_argv);

            resultado = new PyArray("result.txt");
            cout << "Matriz Transposta:" << endl;
            printVector(resultado->getMatriz());
            break;

         case 7:
            py_argv[0] = (char *)"print-function.py";

            cout << "Digite o nome do arquivo da função: " << endl;
            cout << ">>> ";
            cin >> firstEntry;
            function = new PyFunction(firstEntry);
            py_argv[1] = (char *)function->getFilename().c_str();
            cout << "Função Escolhida:" << endl;
            printFunction(function->getFunction());           

            py_argv[2] = (char *)" ";
            runPyScriptArgs(py_argv[0], py_argc, py_argv);
            break;

         case 8:
            cout << "Finalizando o programa." << endl;
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