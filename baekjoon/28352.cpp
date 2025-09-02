#include <iostream>

using namespace std;

int main() {
    int N;
    long long total = 1;
    cin >> N;

    for(int i = 2; i <= N; i++) {
        total *= i;
    }

    
    total /= 60;
    total /= 60;
    total /= 24;
    total /= 7;

    cout << total;
}