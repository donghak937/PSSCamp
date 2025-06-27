#include <iostream>
#include <vector>

using namespace std;

int main(){ 
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    int answer = 0;
    int index = 0;
    bool isOk = true;
    for(string now : skill_trees){
        for(int i = 0; i < skill.size(); i++){
            if (index == string::npos && now.find(skill[i]) != string::npos){
                isOk = false;
                break;
            }
            else if (index <= now.find(skill[i]) || index == string::npos){
                index = now.find(skill[i]);
            }
            else{
                isOk = false;
                break;
            }
        }
        index = 0;
        if (isOk) {
            answer++;
        }
        isOk = true;

    }
    cout << answer;
}