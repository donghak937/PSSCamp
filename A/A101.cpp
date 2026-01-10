#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> aliceSizes = {1,1};
    vector<int> bobSizes {2,2};

    int aTotal = 0;
    int bTotal = 0;
    vector<int> answer;

    for(int a : aliceSizes) aTotal += a;
    for(int a : bobSizes) bTotal += a;

    int diff = (bTotal - aTotal) / 2;

    set<int> s(bobSizes.begin(), bobSizes.end());


    for(int a : aliceSizes){
        if (s.count(a + diff)) {
            answer.push_back(a);
            answer.push_back(a + diff);
            break;
        }
        else continue;
    }
}
