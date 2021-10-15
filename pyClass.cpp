#include <iostream>

#include "pyClass.h"

using std::cout;
using std::endl;

CPyInstance::CPyInstance() {
   Py_Initialize();
}

CPyInstance::~CPyInstance() {
   Py_Finalize();
}

ostream &operator<<(ostream &output, PyArray &array) {
   return output;
}

PyArray::PyArray(string fileName) {
   setFileName(fileName);
}

PyArray operator+(PyArray &firstArray, PyArray &secondArray) {
   return firstArray;
}

void PyArray::setFileName(string fileName) {
   this->fileName = fileName;
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

void runPyScriptArgs(const char *file, int argc, char *argv[]) {   
   FILE *fp;   
   wchar_t **wargv = new wchar_t *[argc];

   for (int i = 0; i < argc; i++) {
      wargv[i] = Py_DecodeLocale(argv[i], nullptr);
      if (wargv[i] == nullptr) {
         return;
      }
   }
   Py_SetProgramName(wargv[0]);

   PySys_SetArgv(argc, wargv);
   fp = _Py_fopen(file, "r");
   PyRun_SimpleFile(fp, file);

   for (int i = 0; i < argc; i++) {
      PyMem_RawFree(wargv[i]);
      wargv[i] = nullptr;
   }

   delete[] wargv;
   wargv = nullptr;   
}