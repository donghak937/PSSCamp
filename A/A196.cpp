#include <iostream>

using namespace std;

int main() {
    int size;
    int find_num;
    int a[100] = {0};
    int count = 0;
    
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    cin >> find_num;

    for (int i = 0; i < size; i++) {
        if (find_num == a[i]) {
            count++;
        }
    }
    cout << count;
    
    return 0;
}