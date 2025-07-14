#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    
    int N;
    cin >> N;
    vector<int> a;
    for(int k = 0; k < N; k++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for(int p : a) {
        cout << p << " ";
    }
}