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

template <class T>
void printFunction(vector<pair<T, T>> const &function) {
   for (pair<T, T> row : function) {      
      cout << row.first << " " << row.second << endl;
   }
   cout << endl;
}

#endif