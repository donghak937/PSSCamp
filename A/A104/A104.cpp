#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> answer;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        answer.push_back(tmp);
    }
    int total = 0;
    auto it = max_element(answer.begin(), answer.end());
    *it = 0;
    for(int i = 0; i < N; i++){
        total += answer[i];
    }

    cout << total;
}
