#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;

    int time1 = A + C;
    int time2 = B + D;

    if (time1 < time2) cout << "Hanyang Univ." << endl;
    else if (time1 > time2) cout << "Yongdap" << endl;
    else cout << "Either" << endl; 
}
