#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';
    string e = to_string(a) + to_string(b);
    cout << stoi(e) - c;

}