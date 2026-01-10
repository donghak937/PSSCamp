#include <iostream>

using namespace std;

int main(){
    int x = 14;
    double answer = x;

    if (x == 1 || x == 0) return x;

    for(int i = 0; i < 100; i++){
        answer = (answer + x / answer) / 2;
    }
    if ((int)answer == answer) cout << true;
    else cout << false;
} 