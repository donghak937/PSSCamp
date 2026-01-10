#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    cout << nums.size();
}
