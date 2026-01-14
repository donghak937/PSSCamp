#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int price = 3,money = 20, count = 4;
    long long answer = 0;
    
    for(int i = 1; i <= count; i++){
        answer += price * i;
    }
    if (answer - money < 0) return 0;
    return answer - money;

}