#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int left = 47;
    int right = 85;
    bool isOk = true;
    vector<int> answer;

    for(int i = left; i <= right; i++){
        string a = to_string(i);

        if (a.find("0") != string::npos) continue;
        else {
            for(int j = 0; j < a.size(); j++){
                if (i % (a[j] - '0') != 0){
                    isOk = false;
                    break;
                }
            }
        } 
        if (isOk) answer.push_back(i);
        isOk = true;
    }

    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;
} 