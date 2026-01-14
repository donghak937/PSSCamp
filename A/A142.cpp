#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> arr = {1,1,3,3,0,1,1};
    vector<int> answer;
    bool isSame = false;
    for(int i = 0; i < arr.size(); i++){
        if(i == 0) answer.push_back(arr[i]);
        else if (arr[i-1] == arr[i]) continue;
        else answer.push_back(arr[i]);
    }

}