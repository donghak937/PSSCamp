#include <iostream>

using namespace std;

int main() {
    int a, b;
    int count = 0;
    cin >> a >> b;

    for(int i = 1; i <= a; i++){
        if (a % i == 0) count++;
        if (count == b){
            cout << i;
            return 0;
        }
    }
    cout << "0";
}