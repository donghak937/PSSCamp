#include <iostream>

using namespace std;

int main(){
    int max = 0;
    int index = 0;
    int current = 0;
    int temp;
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            cin >> temp;
            current += temp;
        }
        if (current > max){
            max = current;
            index = i + 1;
        }
        current = 0;

    }
    cout << index << " " << max;
} 