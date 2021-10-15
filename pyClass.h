#ifndef PYCLASS_H
#define PYCLASS_H

#include <Python.h>
#include <vector>

using namespace std;

void runPyScriptArgs(const char *, int, char *[]);

class CPyInstance
{
   public:
      CPyInstance();

      ~CPyInstance();
};

class PyArray : public CPyInstance {
   public:
      PyArray(string);

      void setFileName(string);
      string getFilename();

      vector<vector<double>> getMatriz();

   private:
      string fileName;

      vector<vector<double>> matriz;

      int setMatriz(string);
};

#endif