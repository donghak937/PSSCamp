#include <vector>

using namespace std;

int solution(vector<int> number) {
    int n = (int)number.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (number[i] + number[j] + number[k] == 0) cnt++;
            }
        }
    }
    return cnt;
}
