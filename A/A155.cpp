#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long k, n;
    vector<int> len; 

    cin >> k >> n;
    long long hi;

    for(int i = 0; i < n; i ++){
        long long a;
        cin >> a;
        len.push_back(a);

        if (a > hi) hi = a;
    }

    long long lo = 1;
    long long ans;

    
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;

        long long pieces = 0;
        for (int i = 0; i < k; i++) {
            pieces += len[i] / mid;
        }

        if (pieces >= n) {      
            ans = mid;
            lo = mid + 1;
        } else {                
            hi = mid - 1;
        }
    }
    cout << ans << "\n";

    

}