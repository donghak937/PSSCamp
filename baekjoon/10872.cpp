#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long answer = 1;

    for(int i = 1; i <= n; i++){
        answer *= i;
    }

    cout << answer;

}