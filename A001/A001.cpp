#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {3};
    sort(g.begin(), g.end());
    int i = 0, j = 0, count = 0;
    if (g.size () == 0 || s.size() == 0) return 0;
    
    while (g[g.size() - 1] != 0 && s[s.size() - 1] != 0){
        while (g[i] != 0 && j < s.size() - 1){
            if (s[j] >= g[i]){
                g[i] = 0;
                s[j] = 0;
                j = 0;
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    cout << count;
}