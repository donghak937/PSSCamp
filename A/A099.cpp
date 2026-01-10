#include <iostream>
#include <string>
#include <stack>

using namespace std;

char matched(char a){
    if (a == ')') return '(';
    if (a == '}') return '{';
    return '[';
}

int main() {
    string s = "()()()";
    stack<char> a;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            a.push(s[i]);
        }
        else{
            if (a.empty()) return false;
            else if (a.top() != matched(s[i])) return false;
            a.pop();
        }
    }
    if (!a.empty()) return false;
    return true;
}
