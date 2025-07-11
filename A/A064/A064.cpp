#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> heights = {1,1,4,2,1,3};
    vector<int> copy(heights);
    sort(copy.begin(), copy.end());

    int count = 0;

    for(int i = 0; i < copy.size(); i++){
        if (copy[i] != heights[i]) count++;
    }
    cout << count;
}