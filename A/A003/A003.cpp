#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<int> digits = {9};
    digits[digits.size() - 1]++;
    for(int i = digits.size() - 1; i >= 0; i--){
        if (digits[i] == 10){
            if (i == 0){
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }
            else{
                digits[i] = 0;
                digits[i - 1]++;
            }
        }
    }
    for(int i = 0; i < digits.size(); i++){
        cout << digits[i] << " ";
    }
}