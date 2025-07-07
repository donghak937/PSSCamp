#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a; 
    
    for(int i = 0; i < 8; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    if (is_sorted(a.begin(), a.end(), greater<int>())) cout << "descending";
    else if (is_sorted(a.begin(), a.end())) cout << "ascending";
    else cout << "mixed";
}