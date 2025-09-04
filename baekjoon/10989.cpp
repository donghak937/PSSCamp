#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    set<int> a;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int c;
        cin >> c;
        a.insert(c);
    }
    for (int x : a) cout << x << "\n";
}