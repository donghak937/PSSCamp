#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s = "A man, a plan, a canal: Panama";
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c);}), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string s2 = s;
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < s2.size(); i++){
        if (s[i] != s2[i]) return false;
    }
    return true;
}
