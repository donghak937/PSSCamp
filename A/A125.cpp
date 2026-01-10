#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> ropes;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int a;
        cin >> a;
        ropes.push_back(a);
    }
    sort(ropes.begin(), ropes.end());
    int max = 0;

    for(int i = ropes.size()-1; i >= 0; i--){
        if (ropes[i] * (n - i) > max){
            max = ropes[i] * (n - i);
        }
    }
    cout << max;

}