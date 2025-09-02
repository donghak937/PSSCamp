#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<char> a;
    cin >> N;
    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        a.push_back(c);
    }

    char k;
    cin >> k;

    cout << count(a.begin(), a.end(), k);
}