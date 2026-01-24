#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, n;
    vector<long long> len; 

    cin >> k >> n;
    long long hi = 0;

    for(int i = 0; i < k; i ++){
        long long a;
        cin >> a;
        len.push_back(a);

        if (a > hi) hi = a;
    }

    long long lo = 0;
    long long ans = 0;
    
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;

        long long pieces = 0;
        for (int i = 0; i < k; i++) {
            if (len[i] - mid > 0) {
                pieces += len[i] - mid;
            }
        }

        if (pieces >= n) {      
            ans = mid;
            lo = mid + 1;
        } 
        else {                
            hi = mid - 1;
        }
    }
    cout << ans << "\n";

}