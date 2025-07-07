#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    string num;
    int a[10] = {0,};
    int count = 1;
    cin >> num;
    int max = 0;

    for(int i = 0; i < num.size(); i++){
        if (num[i] - '0' == 6 || num[i] - '0' == 9){
            if (count % 2 != 0){
                a[6]++;
                count++;
            }
            else {
                count++;
            }
        }
        else a[num[i] - '0']++;
    }

    for(int i = 0; i < 10; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    cout << max;
}