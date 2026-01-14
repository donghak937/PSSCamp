#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> nums = {3,1,2,3};

    int choose = nums.size() / 2;
    int answer;

    sort(nums.begin(), nums.end());                 
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    answer = nums.size() > choose ? choose : nums.size();

    return answer;


}