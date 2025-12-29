#include <iostream>

using namespace std;

int main() {
    int n;
    int dp[10001];
    int score[10000];
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int b;
        cin >> b;
        score[i] = b;
    }
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[2], score[1]) + score[3];

    for(int i = 4; i <= n; i++){
        dp[i] = max (dp[i-2], dp[i-3]+ score[i-1]) + score[i];
    }
    cout << dp[n];
}