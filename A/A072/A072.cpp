#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string date = "2019-01-09";
    stringstream ss(date);
    string part;
    vector<int> arr;

    while (getline(ss, part, '-')) {
        arr.push_back(stoi(part));
    }

    int year = arr[0];
    int month = arr[1];
    int day = arr[2];

    vector<int> Month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) Month[1] = 29;

    int total = 0;
    for (int i = 0; i < month - 1; ++i) {
        total += Month[i];
    }

}
