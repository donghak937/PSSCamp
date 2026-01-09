#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    map<string, int> cnt;
    cin >> n;
    int mx;
    for(int i = 0; i < n; i ++){
        string s;

        cin >> s;
        mx = max(mx, cnt[s]++);

    }
    for (auto &p : cnt) {
        if (p.second == mx) {
            cout << p.first << "\n";
            break; 
        }
    }
}