#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int n = 10012312;
    bitset<32> b(n);
    string s = b.to_string();
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '1') count++;
    }
    cout << count;
}
