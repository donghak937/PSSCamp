#include <iostream>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    int total = ((a + 1) * (b + 1)) / (c + 1) - 1;
    cout << total;

}