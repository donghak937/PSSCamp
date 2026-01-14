#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s = "()()";

    int count = 0;
    
    for(int i = 0; i < s.size(); i++){
        if (count == 0 && s[i] == ')' ) return false;
        else if (s[i] == '(') count++;
        else if (s[i] == ')') count--;
    }

}