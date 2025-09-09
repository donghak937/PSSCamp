#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<bool> v(m + 1, true);
    
    for (int i = 2; i * i <= m; i++) {
        if (v[i]) {
            for (int k = i * i; k <= m; k += i) {
                v[k] = false;
            }
        }
    }
    
    v[1] = true;
    for (int i = n; i < v.size(); i++) {
        if(v[i]) cout << i << '\n';
    }

    return 0;
}