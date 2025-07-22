#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int month = 5;
    int day = 24;
    int year = 2022;
    vector<string> c = {"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int total = 0;
    int n;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth[1] = 29;
    for (int i = 0; i < month - 1; i++) {
        total += daysInMonth[i];
    }
    total += day;

    for(int i = 1971; i < year; i++){
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) total += 366;
        else total += 365;
    }

    n = ((total + 4 )% 7)  ;
    
    cout << c[n];
}