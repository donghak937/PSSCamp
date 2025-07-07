#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int b[26] = {0};
    int max = 0;
    char index;

    cin >> a;
    int size = a.length();

    for (int i = 0; i < size; i++) {
        if (a[i] >= 'a') {
            b[a[i] - 'a']++;
        } else {
            b[a[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (b[i] > max) {
            max = b[i];
            index = i + 'A';
        } else if (b[i] == max) {
            index = '?';
        }
    }

    cout << index;
}
