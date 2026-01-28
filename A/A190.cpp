#include <iostream>

using namespace std;

int main() {
    int d1, d2, d3, total = 0;
    int max;
    cin >> d1 >> d2 >> d3;
    
    if (d1 > d2 && d1 > d3) {
        max = d1;
    }
    else if (d2 > d1 && d2 > d3) {
        max = d2;
    }
    else {
        max = d3;
    }
    
    if (d1 == d2 && d2 == d3) {
        total += 10000 + (d1 * 1000);
    }
    else if (d1 == d2 || d1 == d3 || d2 == d3) {
        if (d3 == d2) {
            total += 1000 + (d3 * 100);
        }
        else {
            total += 1000 + (d1 * 100);
        }
    }
    else {
        total += max * 100;
    }
    
    cout << total;
}