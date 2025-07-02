#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int tmp;
    int answer = 0;
    cin >> N;
    vector<int> a;
    vector<int> b;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        a.push_back(tmp);
    }

    for(int i = 0; i < N; i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for(int i = 0; i < N; i++){
        answer += a[i] * b[i];
    }
    cout << answer;

}