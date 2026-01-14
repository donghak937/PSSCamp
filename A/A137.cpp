#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long long N, K;
    cin >> N >> K;

    long long lo = 1, hi = K; 
    while (lo < hi) {
        long long mid = (lo + hi) / 2;

        long long cnt = 0;
        for (long long i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt >= K) hi = mid;      
        else lo = mid + 1;          
    }

    cout << lo << "\n";

}
