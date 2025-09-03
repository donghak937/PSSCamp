#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int h, w, a;
        int k;
        string answer = "";
        cin >> h >> w >> a;
        if (a % h == 0) answer += to_string(h);
        else answer += to_string(a % h);
        k = a / h;
        if (a % h != 0) k++;
        if (k < 10) answer += '0'; 
        answer += to_string(k);
        cout << answer << endl;
    }

}