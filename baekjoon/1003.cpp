#include <iostream>

using namespace std;

int main() {
    int a[41];
    int b[41];
    a[0] = 1;
    b[0] = 0;
    a[1] = 0;
    b[1] = 1;


    int n;
    cin >> n;
    for(int i = 2; i <= 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        cout << a[k] << " " << b[k] << '\n';
    }

    
}

