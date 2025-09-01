#include <iostream>

using namespace std;

int main() {
    
    while(true){
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;
        if (a == b && c == b) cout << "Equilateral" << endl;

        else if (a >= b && a >= c && b + c <= a) cout << "Invalid"<< endl;
        else if (b >= a && b >= c && a + c <= b) cout << "Invalid"<< endl;
        else if (c >= b && c >= a && b + a <= c) cout << "Invalid"<< endl;
        else if (a != b && b != c && a != c) cout << "Scalene"<< endl;
        else cout << "Isosceles"<< endl;
    }
    
}