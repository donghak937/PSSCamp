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
    int n;
    cin >> n;


    for(int i = 0; i < n; i ++){
        bool isOk = true;
        stack<char> a;
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++){
            if (isOpenBracket(s[j])) a.push(matchBracket(s[j]));

            else if (isCloseBracket(s[j])){
                if (a.empty()){
                    isOk = false;
                    break;
                }
                else if (a.top() == s[j]){
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
        if(isOk) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}