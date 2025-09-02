#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1 ; i < n; i++) {
        int answer = 0;
        int a = i;
        while (a != 0) {
            answer += a % 10;
            a /= 10;
        }

        if (i + answer == n){
            cout << i;
            return 0;
        }

    }
    cout << "0";
}