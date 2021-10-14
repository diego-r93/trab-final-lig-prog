#include <Python.h>

#include <iostream>

using namespace std;

static void runPyScriptArgs(const char *file, int argc, char *argv[]) {
   Py_Initialize();
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
   Py_Finalize();
}

int main() {
   int py_argc = 3;
   char *py_argv[py_argc];

   string firstEntry, secondEntry;

   py_argv[0] = (char *)"add.py";

   cout << "Digite o nome do arquivo da primeira matriz: " << endl;
   cout << ">>> ";
   cin >> firstEntry;
   py_argv[1] = (char *)firstEntry.c_str();

   cout << "Digite o nome do arquivo da segunda matriz: " << endl;
   cout << ">>> ";
   cin.ignore();
   cin >> secondEntry;
   py_argv[2] = (char *)secondEntry.c_str();

   runPyScriptArgs(py_argv[0], py_argc, py_argv);

   return 0;
}