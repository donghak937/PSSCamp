#include <iostream>

using namespace std;

int main(){
    int riding[4];
    int outting[4];
    int current = 0;
    int max = 0;
    for(int i = 0; i < 4; i++){
        cin >> outting[i];
        cin >> riding[i];
        current += riding[i];
        current -= outting[i];
                
        if (current > max){
            max =current;
        }
    }
    cout << max;
}