#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0){
        cout << "0";
        return 0;
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    double g = n * 0.15;
    int a = round(g);
    for(int i = 0; i < a; i++){
        v.pop_back();
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < a; i++){
        v.pop_back();
    }
    double total = 0;
    for(int i = 0; i < v.size(); i++){
        total += v[i];
    }
    total /= v.size();

    cout << round(total);
    
}