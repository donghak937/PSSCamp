#include <iostream>
#include <stack>

using namespace std;

bool isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '{';
}
bool isCloseBracket(char c) {
    return c == '}' || c == ')' || c == ']';
}

char matchBracket(char c) {
    if (c == '(') return ')';
    if (c == '[') return ']';
    if (c == '{') return '}';
    return '\0';

}

int main() {
    while(true){
        bool isOk = true;
        stack<char> a;
        string s;
        getline(cin, s);
        if (s == ".") break;

        for(int i = 0; i < s.size(); i++){
            if (isOpenBracket(s[i])) a.push(matchBracket(s[i]));

            else if (isCloseBracket(s[i])){
                if (a.empty()){
                    isOk = false;
                    break;
                }
                else if (a.top() == s[i]){
                    a.pop();
                    continue;
                }
                else {
                    isOk = false;
                    break;
                }
            }
        }
        if (!a.empty()) isOk = false;
        if(isOk) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}