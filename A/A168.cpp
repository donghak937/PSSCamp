#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>()); // 내림차순

    int ans = 0;
    for (int i = m - 1; i < (int)score.size(); i += m) {
        ans += score[i] * m;
    }
    return ans;
}
