#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int val = 2;
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    cout << nums.size();
}
