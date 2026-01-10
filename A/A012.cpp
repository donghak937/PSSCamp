#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 10;
    int answer = 0;
    vector<bool> a(n + 1, true);

    a[0] = false;
    a[1] = false;
    
    for(int i = 2; i < n; i++){ 
        if (a[i]){
            for(int j = i*2; j < n; j += i){
                a[j] = false;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if (a[i]) answer++;
    }

    cout << answer;
    //2의 배수 전부 지우고
    //3의 배수 전부 지우고
    //4 -> 스킵
    //5의 배수 전부 지우고
    //...
    //10 -> 스킵


}


