#include <iostream>
#include <vector>

using namespace std;

int main() {

    int S, C;
    cin >> S >> C;

    vector<long long> len(S);
    long long hi = 0;
    long long total = 0;

    for (int i = 0; i < S; i++) {
        cin >> len[i];
        hi = max(hi, len[i]);
        total += len[i];
    }

    long long lo = 1;
    long long best = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2; 
        long long pieces = 0;

        for (int i = 0; i < S; i++) {
            pieces += len[i] / mid;
            if (pieces >= C) break; 
        }

        if (pieces >= C) {          
            best = mid;
            lo = mid + 1;
        } else {                    
            hi = mid - 1;
        }
    }

    long long ramen = total - best * (long long)C;
    cout << ramen << "\n";
    return 0;
}
