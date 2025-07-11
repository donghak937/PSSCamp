#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    string s = "aaxxsaxascas";
    stack<char> a;
    string answer;
    for(int i = 0; i < s.size(); i++){
        if (a.empty()) a.push(s[i]);
        else if (a.top() == s[i]) a.pop();
        else a.push(s[i]);
    }
    while (!a.empty()) {
        answer += a.top(); 
        a.pop();       
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
}
