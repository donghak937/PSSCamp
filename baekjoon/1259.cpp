#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        string n;
        cin >> n;

        if (n == "0") break;

        string n2 = n;
        reverse(n2.begin(), n2.end());

        if (n == n2) cout << "yes" << endl;
        else cout << "no" << endl; 

    }
    
}