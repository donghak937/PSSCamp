#include <iostream>
#include <string>

using namespace std;

int main(){
    string num = "4177252841";
    int k = 4;
    int i = 0;
    cout << "num : " << num << endl;
    while(k != 0){
        if (i + 1 == num.size() || num[i] < num[i+1]){
            num.erase(i, 1);
            k--;
            i = 0;
        }
        else i++;
    } 
}