#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        long a, b, c;
        long high;
        cin >> a >> b >> c;
        high = max({a, b, c});

            if (a >= b && a >= c) a = 0;
            else if (b >= a && b >= c) b = 0;
            else c = 0;
        
        if (a == 0 && b == 0 && c == 0) break;
        if (a * a + b * b + c * c == high * high) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
}