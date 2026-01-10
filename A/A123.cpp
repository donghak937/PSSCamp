#include <iostream>

using namespace std;

int main() {
    int a;
    int count = 0;
    cin >> a;
    while (a != 1) {
        if (a % 3 == 0){
            if (a / 3 > (a - 1) / 3){
                a /= 3;
            }
            else {
                a--;
                a /= 3;
                count++;
            } 
        }
        else if (a % 2 == 0){
            if (a / 2 > (a - 1) / 2){
                a /= 3;
            }
            else {
                a--;
                a /= 2;
                count++;
            }
        }
        else a--;
    }

    cout << count;
    
}