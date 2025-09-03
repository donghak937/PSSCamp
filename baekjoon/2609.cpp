#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int n = a > b ? a : b;
    int max = 0;
    for(int i = 1; i <= n; i++){
        if (a % i == 0 && b % i == 0){
            max = i;
        }
    }
    cout << max << '\n' << int(a * b / max);
}