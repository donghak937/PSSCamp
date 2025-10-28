#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    int n;
    cin >> n;
    vector<string> a; 
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        a.push_back(s);
    }

    sort(a.begin(), a.end(), [](const string &x, const string &y) {
        if (x.length() == y.length()) return x < y;
        return x.length() < y.length();
    });
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for(const auto& s : a) {
        cout << s << '\n';
    }

}