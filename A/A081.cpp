#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    
    int N;
    cin >> N;
    for(int k = 0; k < N; k++){
        vector<int> nums;
        for(int i = 0; i < 10; i++){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end());
        cout << nums[7] << endl;
    }
}