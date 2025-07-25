#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {1,2,2,1,2,1,1,1,1,2,2,2};
    unordered_map<int,int> a;
    for(int num : nums){
        a[num]++;
    }
    int max = 0;
    int maxnum = -1;
    vector<int> maxs;

    for (auto& p : a) {
        if (p.second == max) {
            maxnum = p.first;
            maxs.push_back(maxnum);
        }
        else if (p.second > max) {
            maxs.clear();
            max = p.second;
            maxnum = p.first;
            maxs.push_back(maxnum);
        }
    }

    int count = 0;
    int min = 50001;
    for(int i = 0; i < maxs.size(); i++){
        vector<int> c(nums);
        while (true) {
            if (c[0] != maxs[i]) c.erase(c.begin());
            else if (c[c.size() - 1] != maxs[i]) c.pop_back();
            else break;
        }

        if (c.size() < min) min = c.size();
        
    }
    cout << min;
}