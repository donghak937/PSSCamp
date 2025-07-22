#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
        result %= 1000000007;
    }
    return result;
}

int main() {
    int n = 100;
    int total = 0;
    int index = 0;
    vector<bool> a(n + 1, true);

    a[0] = false;
    a[1] = false;
    
    for(int i = 2; i <= n; i++){ 
        if (a[i]){
            for(int j = i*2; j <= n; j += i){
                a[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if (a[i]) total++;
    }
    
    cout << (factorial(total) * factorial(n - total)) % 1000000007;

}   