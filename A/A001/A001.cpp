#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {3};
    int i = 0, j = 0, count = 0;
    if (g.size () == 0 || s.size() == 0) return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (i < g.size() && j < s.size()){
        if (g[i] <= s[j]){
            i++;
            count++;
        }
        j++;
    }
    return count;
    cout << count;
}