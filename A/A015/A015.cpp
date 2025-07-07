#include <iostream>

using namespace std;

int main(){
    int total = 0;
    int num;
    for(int i = 0; i < 5; i ++){
        cin >> num;
        total += num * num;
    }
    cout << total % 10;
}