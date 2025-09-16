#include <iostream>
using namespace std;

int main() {
    int n;
    int answer = 0;
    cin >> n;

    while (n != 0) {
        if (n < 3){
            cout << "-1";
            return 0;
        }
        if (n % 5 == 0){
            answer += (n / 5);
            n /= 5;
            cout << answer;
            return 0;
        }
        n -= 3;
        answer++;
    }
    cout << answer;
    
}
