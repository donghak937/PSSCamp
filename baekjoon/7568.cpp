#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> v;
    int a[51] = {0};
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        pair<int, int> s;
        cin >> s.first >> s.second;
        v.push_back(s);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (v[i].first < v[j].first && v[i].second < v[j].second){
                a[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        cout << (a[i] + 1) << " ";
    }
}
   