#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int total = 0;
    bool isOk = true;
    cin >> a;
    int m = 10 - (a[12] - '0');

    for(int i = 0; i < a.size() - 1; i++){
        if (a[i] == '*'){
            if (i % 2 != 0) isOk = false;
        }
        else if (i % 2 == 0 || i == 0) total += a[i] - '0';
        else total += (a[i] - '0') * 3;
    }

    total %= 10;
    m -= total;

    if(isOk) cout << m;
    else cout << m/3;
}