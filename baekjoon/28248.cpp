#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int total = a > b ? 500 : 0;
    total += a *50;
    total -= b *10;
    cout << total;

}