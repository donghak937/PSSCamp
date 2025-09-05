#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int f;
        cin >> f;
        a.insert(f);
    }

    for (int num : a) {
        cout << num << '\n';
    }
}