#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s = {"a234"};
    if (s.size() != 4 && s.size() != 6) return false;
    for(int i = 0; i < s.size(); i++){
        if (!(s[i] >= '0' && s[i] <= '9')) return false;
    }
    return true;
}