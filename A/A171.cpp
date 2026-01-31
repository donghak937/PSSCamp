#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int ans = 0;

    while (n >= a) {
        int give = (n / a) * b;   // 새로 받은 콜라(=새 빈병)
        ans += give;
        n = (n % a) + give;       // 남은 빈병 + 새로 생긴 빈병
    }

    return ans;
}
