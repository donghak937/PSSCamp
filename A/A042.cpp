#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s = "xywrrmp";
    string t = "xywrrmu#p";

    stack<char> a;
    stack<char> b;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '#'){
            if (a.empty()) continue;
            a.pop();
        } 
        else a.push(s[i]);
    }
    
    for (int i = 0; i < t.size(); i++){
        if (t[i] == '#'){
            if (b.empty()) continue;
            b.pop();
        } 
        else b.push(t[i]);
    }


    cout << (a==b);
} 