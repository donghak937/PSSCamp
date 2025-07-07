#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int answer;
    vector<int> nums = {4,1,2,1,2};
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 2){
        if (i >= nums.size() || nums[i] != nums[i+1]){
            answer = nums[i];
            break;
        }
    }
    cout << answer;
    
}