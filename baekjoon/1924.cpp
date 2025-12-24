#include <iostream>
using namespace std;
int main() {
    int day, month;
    cin >> month >> day;
    string daysOfWeek[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    for(int i = 0; i < month - 1; i++) {
        totalDays += daysInMonths[i];
    }
    totalDays += day;
    int dayOfWeekIndex = totalDays % 7;
    cout << daysOfWeek[dayOfWeekIndex] << endl;
}