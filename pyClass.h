#ifndef PYCLASS_H
#define PYCLASS_H

#include <Python.h>

using std::string;

class CPyInstance
{
public:
   CPyInstance()
   {
      Py_Initialize();
   }

   ~CPyInstance()
   {
      Py_Finalize();
   }
};

class CPyObject : public CPyInstance {
   public:

   private:
      string fileName;
};

#endif