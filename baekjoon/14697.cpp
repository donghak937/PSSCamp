#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c, n;
    cin>> a >> b >> c >> n;

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i <= n; i++) {
        if (!dp[i]) continue;
        if (i + a <= n) dp[i + a] = true;
        if (i + b <= n) dp[i + b] = true;
        if (i + c <= n) dp[i + c] = true;
    }

    if (dp[n]) cout << "1\n";
    else cout << "0\n";
}
