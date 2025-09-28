#include <iostream>
using namespace std;

int main() {

    int S, D;
    cin >> S >> D;

    if (S < D) { 
        cout << -1 << '\n';
        return 0; 
    }
    int sp = S + D;
    int sm = S - D;
    if (sp % 2 || sm % 2) { 
        cout << -1 << '\n'; 
        return 0; 
    }

    int x = sp / 2;
    int y = sm / 2;

    if (y < 0) { 
        cout << -1 << '\n'; 
        return 0; 
    }
    cout << x << ' ' << y << '\n';

}
