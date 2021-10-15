#include <fstream>
#include <iostream>
#include <sstream>

#include "pyClass.h"
#include "consts.h"

using namespace std;

CPyInstance::CPyInstance() {
   Py_Initialize();
}

CPyInstance::~CPyInstance() {
   Py_Finalize();
}

PyArray::PyArray(string fileName) {
   setFileName(fileName);
   setMatriz(fileName);
}

void PyArray::setFileName(string fileName) {
   this->fileName = fileName;
}

string PyArray::getFilename() {
   return fileName;
}

int PyArray::setMatriz(string fileName) {
   fstream myFile;
   string line, colname;

   myFile.open(fileName);

   if (!myFile.is_open()) {
      cout << "O arquivo escolhido não existe." << endl;
      return ERROR_OPENING_FILE;
   }

   if (myFile.good()) {
      while (getline(myFile, line)) {
         stringstream myStream(line);
         vector<double> row;

         while (getline(myStream, colname, ' ')) {
            row.push_back(stod(colname));
         }

         matriz.push_back(row);
         row = {};
      }
   }

   myFile.close();
   return OKAY;
}

vector<vector<double>> PyArray::getMatriz() {
   return matriz;
}

PyFunction::PyFunction(string fileName) {
   setFileName(fileName);
   setFunction(fileName);
}

void PyFunction::setFileName(string fileName) {
   this->fileName = fileName;
}

string PyFunction::getFilename() {
   return fileName;
}

int PyFunction::setFunction(string) {
   fstream myFile;
   string line, colname;

   myFile.open(fileName);

   if (!myFile.is_open()) {
      cout << "O arquivo escolhido não existe." << endl;
      return ERROR_OPENING_FILE;
   }

   if (myFile.good()) {
      while (getline(myFile, line)) {
         stringstream myStream(line);
         pair<double, double> row;

         getline(myStream, colname, ',');
         row.first = stod(colname);
         getline(myStream, colname, ',');
         row.second = stod(colname);

         function.push_back(row);
         row = {};
      }
   }

   myFile.close();
   return OKAY;
}

vector<pair<double, double>> PyFunction::getFunction() {
   return function;
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