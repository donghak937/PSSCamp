#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {   
            int x;
            cin >> x;

            if (j == 0) dp[j] = dp[j] + x;                 
            else if (j == i) dp[j] = dp[j - 1] + x;         
            else dp[j] = max(dp[j], dp[j - 1]) + x;         
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
