#ifndef PYCLASS_H
#define PYCLASS_H

#include <Python.h>

using std::ostream;
using std::string;

class CPyInstance
{
   public:
      CPyInstance();

      ~CPyInstance();
};

class PyArray : public CPyInstance {
   friend ostream &operator<<(ostream &, PyArray &);

   public:
      PyArray();

      PyArray operator+(const PyArray &);
      PyArray operator-(const PyArray &);
      PyArray operator*(const PyArray &);

   private:
      string pythonScript;
};

#endif