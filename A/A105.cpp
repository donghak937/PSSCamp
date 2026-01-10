#include <iostream>

using namespace std;

int main() {
    int a, i = 1;
    int mom = 1, son = 1;
    int check = son;
    int row = 1;

    cin >> a;

    while (i < a) {
        if (mom == check) {
            row++;
            if (mom >= son) {
                mom++;
                check = 1;
                i++;
                continue;
            } else {
                son++;
                check = son;
                i++;
                continue;
            }
        }
        if (row % 2 == 0) {
            son++;
            mom--;
        } else {
            mom++;
            son--;
        }
        i++;
    }

    cout << son << "/" << mom << endl;
    return 0;
}
