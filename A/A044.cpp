#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s = "PPALLL";
    int L = 0;
    int A = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == 'A'){
            A++;
            if (A >= 2) return false;
            L = 0;
        } 
        else if (s[i] == 'L'){
            L++;
            if (L >= 3) return false;
        }
        else {
            L = 0;
        }
    }
    return true;
} 