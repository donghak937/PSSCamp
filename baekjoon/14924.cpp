#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long n = c / (a*2);
    long long answer = n * b;

    cout << answer;

}
