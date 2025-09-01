#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    vector<int> prime;
    int a, b;
    int total = 0;
    bool isOk = true;
    int min;
    cin >> a >> b;
    int number = b;
    for(int i = 0; i <= b; i++){
        prime.push_back(i);
    }

    for (int i = 2; i <= sqrt(b); i++){
        if (prime[i] == 0) continue;
        for (int j = i * i; j <= number; j += i){
            prime[j] = 0;
        }
    }
    for (int i = a; i <= number; i++) {
        if (i == 1) continue;
        if (prime[i] != 0) {
            if (isOk) min = i;
            total += i;
            isOk = false;
        }
    }
    if (total == 0){
        cout << "-1";
        return 0;
    }
    cout << total << "\n" << min;
}