#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> strs = {"dog","racecar","car"};

    string pre;
    string answer;
    bool isOk = true;
    for(int i = 0; i < strs[0].size(); i++){
        pre = strs[0].substr(0,i+1);
        for(string a : strs){
            if (a.substr(0,i+1) == pre) continue;
            else isOk = false;
        }
        if (isOk){
            answer = pre;
        }
        isOk = true;
    }
    cout << answer;
    
} 