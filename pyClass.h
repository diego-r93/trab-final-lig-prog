#ifndef PYCLASS_H
#define PYCLASS_H

#include <Python.h>

using std::ostream;
using std::string;

void displayMenu();
void runPyScriptArgs(const char *, int, char *[]);

class CPyInstance
{
   public:
      CPyInstance();

      ~CPyInstance();
};

class PyArray : public CPyInstance {
   friend ostream &operator<<(ostream &, PyArray &);
   friend PyArray operator+(PyArray &, PyArray &);
   
   public:
      PyArray(string);

      void setFileName(string);

   private:
      string fileName;
};

#endif