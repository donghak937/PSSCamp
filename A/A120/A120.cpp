#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s = "asd";
    string t = "asdr";
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i = 0; i < s.size(); i++){
        if (s[i] != t[i]) return t[i];
    }
    cout << t[t.size() - 1];
}