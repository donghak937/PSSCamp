#include <iostream>
using namespace std;

int main() {
    int num;
    int total = 0;
    cin >> num;

    for (int i = 0; i <= num; i++) {
        total += i;
    }
    cout << total;
}