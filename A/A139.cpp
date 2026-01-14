#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int oneCnt = 0;
    int zeroCnt = 0;

    if (s[0] == '0') zeroCnt++;
    else oneCnt++;

    for(int i = 0; i < s.size()-1; i++){
        
        if(s[i] == s[i+1]) continue;
        else {
            if(s[i+1] == '1') oneCnt++;
            else zeroCnt++;
        }

    }

    cout << min(zeroCnt, oneCnt);

}