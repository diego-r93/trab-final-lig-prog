#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

using namespace std;

void displayMenu();

template <class T>
void printVector(vector<vector<T>> const &matrix) {
   for (vector<T> row : matrix) {
      for (T val : row) {
         cout << val << " ";
      }
      cout << endl;
   }
   cout << endl;
}

#endif