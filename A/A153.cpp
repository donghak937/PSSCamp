#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> a;

    cin >> n;

    int time = 0;
    int total = 0;

    for(int i = 0; i < n; i++){
        int b; 
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        time += a[i];
        total += time;
    }

    cout << total;

}