#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    auto pos = s.find("gori"); 
    if (pos != string::npos) cout << "YES";
    else cout << "NO";
}