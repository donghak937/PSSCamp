#include <iostream>

using namespace std;

int main() {
    int N;
    int dp[12];
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        cout << dp[a] << '\n';
    }

}