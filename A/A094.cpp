#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    int total = 0;
    int size = a.size();

    for (int i = 0; i < size; i++) {
        if (a[i] == 'c' && a[i + 1] == '=') {
            total++;
            i++;
        }
        else if (a[i] == 'c' && a[i + 1] == '-') {
            total++;
            i++;
        }
        else if (a[i] == 'd' && a[i + 1] == 'z' && a[i + 2] == '=') {
            total++;
            i += 2;
        }
        else if (a[i] == 'd' && a[i + 1] == '-') {
            total++;
            i++;
        }
        else if (a[i] == 'l' && a[i + 1] == 'j') {
            total++;
            i++;
        }
        else if (a[i] == 'n' && a[i + 1] == 'j') {
            total++;
            i++;
        }
        else if (a[i] == 's' && a[i + 1] == '=') {
            total++;
            i++;
        }
        else if (a[i] == 'z' && a[i + 1] == '=') {
            total++;
            i++;
        }
        else total++;
    }

    cout << total;

    return 0;
}
