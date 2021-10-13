#ifndef PYHELPER_HPP
#define PYHELPER_HPP

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