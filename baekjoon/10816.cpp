#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    int m;
    vector<long long> a;
    vector<int> b;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        a.push_back(l);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int l;
        cin >> l;
        b.push_back(l);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++){
        cout << upper_bound(a.begin(), a.end(), b[i]) - lower_bound(a.begin(), a.end(), b[i]) << ' ';
    }
    
    
}

