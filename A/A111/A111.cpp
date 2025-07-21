#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int how;
        cin >> how;
        int tmp = 1;
        int count = 0;
        int half = 0;
        while (count != how) {
            tmp *= 2;
            half++;
            if (half == 2){
                tmp += 1;
                half = 0;
            }
            count++;
        }
        cout << count << endl; 
    }
}