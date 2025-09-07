#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        pair<int, int> s;
        cin >> s.first >> s.second;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    for (const auto &p : v) { 
        cout << p.first << " " << p.second << '\n'; 
    }

}
   