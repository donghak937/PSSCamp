#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n1, n2;
    int g;
    int c;

    cin >> n1 >> n2 >> g >> c;

    if (n1 * c + n2 <= g * c && n1 <= g) cout << 1;
    else cout << 0;
}