#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {0,1,0,3,12};
    stable_sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
        if (a == 0) return false;  
        if (b == 0) return true;
        return false;    
    });
}