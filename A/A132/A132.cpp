#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1,y1,r1,x2,y2,r2;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x1 - x2, dy = y1 - y2;

        int d = dx*dx + dy*dy;

        int sum = r1 + r2;

        int diff = abs(r1 - r2);

        int sum2 = sum * sum;
        int diff2 = diff * diff;

        if (d == 0) {
            if (r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            if (d > sum2) cout << 0 << '\n';                 
            else if (d < diff2) cout << 0 << '\n';           
            else if (d == sum2 || d == diff2) cout << 1 << '\n'; 
            else cout << 2 << '\n';                          
        }

        
    }
}