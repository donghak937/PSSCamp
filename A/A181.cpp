#include <iostream>
using namespace std;

int main(){
    int a, b, n, t;
    cin >> a >> b;
    t = a * b;
    n = 10;
    n = b % n;
    b = b - n;
    cout << a * n << "\n";
    n = 100;
    n = b % n;
    b = b - n;
    cout << (a * n) / 10 << "\n";
    n = 100;
    n = b / n;
    cout << a * n << "\n";
    cout << t;
}