#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a = "100";
    string b = "110010";
    bool carry = false;
    string answer;
    if (a.size() < b.size()) {
        a = string(b.size() - a.size(), '0') + a;
    }
    else if (b.size() < a.size()) {
        b = string(a.size() - b.size(), '0') + b;
    }

    for(int i = a.size() - 1; i >= 0; i--){
        if (a[i] == '0' && b[i] == '0'){
            if (carry){
                answer += '1';
                carry = false;
            }
            else answer += '0';
        }

        else if (a[i] == '1' && b[i] == '1'){
            if (carry){
                answer += '1';
            }
            else answer += '0';
            carry = true;
        }
        else {
            if (carry){
                answer += '0';
            }
            else answer += '1';
        }
        cout << answer << endl;
    }
    reverse(answer.begin(), answer.end());
    if (carry){
        answer = '1' + answer;
    }
    
    cout << answer;
}