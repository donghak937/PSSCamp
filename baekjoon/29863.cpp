#include <iostream>
using namespace std;

int main() {
    int s, e;          
    int hours;

    cin >> s >> e;

    if (e >= s) hours = e - s;
    else hours = 24 - s + e;  

    cout << hours;
}
