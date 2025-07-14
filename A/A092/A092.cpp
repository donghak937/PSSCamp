#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    vector<int> nums = {3,4};
    int size = nums.size();
    vector<int> a;
    int k = 0;
    for(int i = 0; i < size; i++){
        if (i % 2 == 0){
            while(nums[k] % 2 != 0){
                k++;
            }
            a.push_back(nums[k]);
            nums.erase(nums.begin() + k);
            k = 0;
        }
        else{
            while(nums[k] % 2 != 1){
                k++;
            }
            a.push_back(nums[k]);
            nums.erase(nums.begin() + k);
            k = 0;       
        }
    }

    for (int n : a) {
        cout << n << " ";
    }
    cout << endl;
}
