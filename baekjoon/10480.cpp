#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num % 2 == 0) cout << num << " is even" << endl;
        else  cout << num << " is odd" << endl;
    }

    return 0;
}
