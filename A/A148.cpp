#include <iostream>
#include <string>

using namespace std;

int main() {

    string a;
    getline(cin, a);           
    int count = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != ' ' && (i + 1 == (int)a.size() || a[i + 1] == ' ')) {
            count++;
        }
    }

    cout << count;
}
