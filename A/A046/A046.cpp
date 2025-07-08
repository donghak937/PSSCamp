#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int size;
    int b[26] = {0};
    bool isOk = false;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> a;
        if (a[0] >= 'a') {
            b[a[0] - 'a']++;
        } 
        else {
            b[a[0] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (b[i] >= 5) {
            cout << (char)(i + 'a');
            isOk = true;
        } 
    }
    if (!isOk) cout << "PREDAJA";

}
