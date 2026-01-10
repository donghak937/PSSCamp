#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    
    string s;
    cin >> s;
    vector<string> a;
    string tmp ="";
    a.push_back(s);
    int size = s.size();
    for(int k = 0; k < size -1; k++){
        s.erase(s.begin());
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    for(const auto& str : a) {
        cout << str << '\n';
    }
}
