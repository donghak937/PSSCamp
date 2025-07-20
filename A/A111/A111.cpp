#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    int mon = 1000 - N;
    int count = 0;
    while(true){
        if (mon / 500 != 0){
            mon -= 500;
            count++;
        }
        else if (mon / 100 != 0){
            mon -= 100;
            count++;
        }
        else if (mon / 50 != 0){
            mon -= 50;
            count++;
        }
        else if (mon / 10 != 0){
            mon -= 10;
            count++;
        }
        else if (mon / 5 != 0){
            mon -= 5;
            count++;
        }
        else {
            count += mon;
            break;
        }
    }
    cout << count;
}