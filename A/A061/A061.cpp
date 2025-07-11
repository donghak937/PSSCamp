#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int columnNumber = 701;
    string a;
    int b = columnNumber;
    int n;
    while (b != 0) {
        cout << b << endl;
        b--;
        n = b % 26;
        if (n == 0) n = 26;
        a += 'A' + n;
        b /= 26;
    } 
    reverse(a.begin(), a.end());
    cout << a;
}