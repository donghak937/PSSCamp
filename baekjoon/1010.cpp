#include <iostream>

using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        long long result = factorial(b) / (factorial(a) * factorial(b - a));
        cout << result << "\n";
    }
}

