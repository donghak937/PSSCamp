#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    
    int N;
    cin >> N;
    vector<pair<int, string>> a;
    for(int k = 0; k < N; k++){
        int age;
        string name;
        cin >> age >> name;
        a.push_back({age, name});
    }
    stable_sort(a.begin(), a.end(), [] (const pair<int, string>& a, const pair<int, string>& b){
        return a.first < b.first;
    });
    for(const auto& p : a) {
        cout << p.first << ' ' << p.second << '\n';
    }
}