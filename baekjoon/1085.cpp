#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    int w, h;
    cin >> a >> b >> w >> h;

    int min = 10000;
    if(abs(a - w) < min) min = abs(a - w);
    if(abs(b - h) < min) min = abs(b - h);
    if(a < min) min = a;
    if(b < min) min = b;
    cout << min;
}