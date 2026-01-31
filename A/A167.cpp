#include <string>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string left;

    for (int i = 1; i < (int)food.size(); i++) {
        int k = food[i] / 2;          // 양쪽에 놓을 수 있는 개수
        left.append(k, char('0' + i)); // i는 1~9라고 가정(문제 조건상 OK)
    }

    string right = left;
    reverse(right.begin(), right.end());

    return left + "0" + right;
}
