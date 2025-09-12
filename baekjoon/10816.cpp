#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(null);
    int n;
    int m;
    vector<int> a;
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
    
    
}