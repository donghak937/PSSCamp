#include <iostream>
#include <string>
using namespace std;

int sectocnt(char a) {
    if (a >= 'A' && a <= 'C') return 3;
    if (a >= 'D' && a <= 'F') return 4;
    if (a >= 'G' && a <= 'I') return 5;
    if (a >= 'J' && a <= 'L') return 6;
    if (a >= 'M' && a <= 'O') return 7;
    if (a >= 'P' && a <= 'S') return 8;
    if (a >= 'T' && a <= 'V') return 9;
    if (a >= 'W' && a <= 'Z') return 10;
    return 0; 
}

int main() {
    string a;
    int total = 0;
    cin >> a;

    for (int i = 0; i < a.size(); i++) {
        total += sectocnt(a[i]);
    }

    cout << total;
}


