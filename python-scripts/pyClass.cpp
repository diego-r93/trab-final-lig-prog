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

ostream &operator<<(ostream &output, PyArray &patient) {
   return;
}

PyArray::PyArray() {

}

PyArray::PyArray operator+(const PyArray &) {

}

PyArray::PyArray operator-(const PyArray &) {

}

PyArray::PyArray operator*(const PyArray &) {

}