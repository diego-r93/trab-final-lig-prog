#include <iostream>
#include <Python.h>

using std::string;

int main()
{
	const char *filename = "matriz.py";
	FILE *fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	Py_Finalize();
	return 0;
}