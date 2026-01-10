#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums = {0,1};
    vector<string> answer;
    string s = "";
    for(int i = 0; i < nums.size(); i++){
        if (s == ""){
            s += to_string(nums[i]);

            if ( i == nums.size() - 1){
                answer.push_back(s);
            }
            else if (nums[i] + 1 != nums[i + 1]){
                answer.push_back(s);
                s = "";
            }
        }
        
        else if (i >= nums.size() - 1){
            s += "->";
            s += to_string(nums[i]);
            answer.push_back(s);
        }
        else if (nums[i] + 1 == nums[i + 1]){
            continue;
        }
        
        else {    
            s += "->";
            s += to_string(nums[i]);
            answer.push_back(s);
            s = "";
        }
    }
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }
}