#include <iostream>

using namespace std;

int main() {
    int trys;
    cin >> trys;

    for (int i = 0; i < trys; i++) {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
    
    return 0;
}