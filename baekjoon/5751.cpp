#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n;
        int mary = 0;
        int john = 0;
        cin >> n;
        if (n == 0) break;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if (a == 0) mary++;
            else john++;
        }
        cout << "Mary won " << mary << " times and John won "<< john << " times" << endl;
    }
}