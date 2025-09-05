#include <iostream>

using namespace std;

long long fac(int n){
    long long total = 1;
    for(int i = 1; i <= n; i++){
        total *= i;
    }
    return total;
}

int main() {
    int a,b;
    cin >> a >> b;

    long long total = fac(a) / (fac(b) * fac(a - b));

    cout << total;

}