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