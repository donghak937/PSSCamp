#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary(int target, vector<int> &v){

    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if(v[mid] == target) return 1;
        else if (v[mid] >= target) right = mid - 1;
        else if (v[mid] <= target) left = mid + 1;
    }
    return 0; 
}

int main() {

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

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++){
        cout << binary(b[i], a) << '\n';
    }
    
    
}

