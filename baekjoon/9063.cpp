#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << "0";
        return 0;
    }
    int xMin = 100000, yMin = 100000;
    int xMax = -100000, yMax = -100000;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if (xMax < a) xMax = a;
        if (yMax < b) yMax = b;

        if (xMin > a) xMin = a;
        if (yMin > b) yMin = b;
    }

    cout << abs(xMax - xMin) * abs(yMax - yMin);
}