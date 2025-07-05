#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int total = 0;
    int temp;
    vector<int> a;
    
    for(int i = 0; i < 10; i++){
        cin >> temp;
        a.push_back(temp % 42);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()), a.end());

    cout << a.size();
} 