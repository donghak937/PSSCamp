#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    int tmp1, tmp2, tmp3;
    int rot = 0;
    int ans = 1;
    for(int i = 0; i < N; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        ans = (ans / tmp1) * tmp2;
        rot ^= tmp3;
    }
    cout << rot << " " << ans;
}