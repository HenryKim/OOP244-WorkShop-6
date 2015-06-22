// Workshop 6 - Staff List
 // w6x.cpp
 // Apr 11 2011

#include <iostream>
#include <iomanip>
#include <cstring>
 using namespace std;
 #include "w6x.h"

 int main() {
     int n = 0;
     char y_or_n;
     bool finished = false;
     Employee employee[MAX_EMPLOYEES];

     cout << "Staff List Processor\n";
     cout << "====================\n";

     do {
         cin >> employee[n];
         bool error;
         do {
             cout << " Do you wish to continue (y or n) ? ";
             cin >> y_or_n;
             error = true;
             if (cin.get() != '\n') {
                 cin.ignore(2000, '\n');
                 cerr << "Trailing characters.  Try again." << endl;
             }
             else if (y_or_n == 'n' || y_or_n == 'N') {
                 error = false;
                 n++;
                 finished = true;
             }
             else if (y_or_n == 'y' || y_or_n == 'Y') {
                 error = false;
                 n++;
             }
             else {
                 cin.ignore(2000, '\n');
                 cerr << " ** Invalid input.  Try again **";
             }
         } while (error);
     } while (!finished && n < MAX_EMPLOYEES);
     cout << endl;

     sort(employee, n);

     cout << "           Staff List\n\n";
     cout << "Number    Rate  Name\n";
     cout << "------------------------------------\n";

     for (int i = 0; i < n; i++)
         cout << employee[i] << endl;
 }

 // sort sorts the elements of employee[size] in ascending order
 //
 void sort(Employee* employee, int n) {

     int i, j;
     Employee temp;

     for (i = n - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
             if (employee[j] > employee[j+1]) {
                 temp          = employee[j];
                 employee[j]   = employee[j+1];
                 employee[j+1] = temp;
             }
         }
     }
 }