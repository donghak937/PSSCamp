#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s = "abcde";
    string goal = "cdeab";
    for(int i = 0; i < s.size(); i++){
        char c = s[0];
        s.erase(0, 1);
        s += c;
        if (goal == s) return true;
        
    }
    return false;    
}