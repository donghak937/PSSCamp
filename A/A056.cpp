#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> answer;

    for(int i = 0; i < nums1.size(); i++){
        auto it = find(nums2.begin(), nums2.end(), nums1[i]);
        if (it == nums2.end()) answer.push_back(-1);
        else{
            for(int j = it - nums2.begin(); j < nums2.size(); j++){
                if(nums2[j] > *it){
                    answer.push_back(nums2[j]);
                    break;
                }
                else if (j == nums2.size() - 1){
                    answer.push_back(-1);
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

}