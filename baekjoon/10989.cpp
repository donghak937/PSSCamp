#include <iostream>

using namespace std;

int main() {
    int a[10001] ={0};
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int c;
        cin >> c;

        a[c]++;
    }
    for (int i = 0; i < 10001; i++){
        for(int j = 0; j < a[i]; j++){
            cout << i << '\n';
        }
    }
}