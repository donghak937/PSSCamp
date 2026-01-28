#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, C;
    cin >> N >> C;

    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    sort(x.begin(), x.end());

    long long lo = 1;
    long long hi = x.back() - x.front();
    long long ans = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        long long last = x[0];
        int cnt = 1; 

        for (int i = 1; i < N; i++) {
            if (x[i] - last >= mid) {
                cnt++;
                last = x[i];
            }
        }

        if (cnt >= C) {  
            ans = mid;
            lo = mid + 1;
        } else {        
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
}
