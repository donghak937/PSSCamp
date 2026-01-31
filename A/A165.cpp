#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    vector<int> divCnt(number + 1, 0);

    for (int i = 1; i <= number; i++) {
        for (int j = i; j <= number; j += i) {
            divCnt[j]++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= number; i++) {
        if (divCnt[i] > limit) sum += power;
        else sum += divCnt[i];
    }

    return sum;
}
