#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string num1;
    string num2;
    string answer = "";
    int size;
    int i;
    int n;
    bool isCarry = false;
    cin >> num1;
    cin >> num2;
    size = num1.size() > num2.size() ? num2.size() : num1.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for(i = 0; i < size; i++){
        n = num1[i] - '0' + num2[i] - '0';
        if (isCarry) n++;
        if (n >= 10){
            isCarry = true;
            n -= 10;
        } 
        else isCarry = false;
        answer += to_string(n);
    }
    size = num1.size() < num2.size() ? num2.size() : num1.size();

    if (num1.size() > num2.size()){
        for(i; i < size; i++){
            n = num1[i] - '0';
            if (isCarry) n++;
            if (n >= 10){
                isCarry = true;
                n -= 10;
            } 
            else isCarry = false;
            answer += to_string(n);
        }
    }
    else{
        for(i; i < size; i++){
            n = num2[i] - '0';
            if (isCarry) n++;
            if (n >= 10){
                isCarry = true;
                n -= 10;
            } 
            else isCarry = false;
            answer += to_string(n);
        }

    }
    if (isCarry) answer += "1";
    reverse(answer.begin(), answer.end());
    cout << answer;
} //다시 할 때는 문자열 그냥 0 넣어서 길이 맞추기