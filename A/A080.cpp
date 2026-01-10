#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    int N = nums.size() / 2;
    int answer = 0;
    for(int a : nums){
        int counts = count(nums.begin(), nums.end(), a);
        if (counts > N) cout << a; 
    }
}