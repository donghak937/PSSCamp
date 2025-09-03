#include <iostream>

using namespace std;

int main() {
    string str;
    int n;
    cin >> n;
    cin >> str;
    long long total = 0;
    long long r = 1;
    for(int i = 0; i < n; i++){
        long long v (str[i] - 'a' + 1);
        total = (total + (v * r) % 1234567891) % 1234567891;
        
        r = (r * 31) % 1234567891;

    }
    cout << total;
}