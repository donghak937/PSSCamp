#include <iostream>
#include <vector>

using namespace std;

int main(){ 
    bool answer;
    string s = "pPoooyY";
    int p = 0;
    int y = 0;

    for(int i = 0; i < s.size(); i++){
        if (s[i] == 'p' || s[i] == 'P') p++;
        else if (s[i] == 'y' || s[i] == 'Y') y++;
    } 

    return p == y ? true : false;
    cout << answer;
}