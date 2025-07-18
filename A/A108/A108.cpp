#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        bool isOk = true;
        cin >> a;
        string s;
        s = to_string(a);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int real = stoi(s2);
        real += a;
        s = to_string(real);
        s2 = s;
        reverse(s2.begin(), s2.end());
        for(int i = 0; i < s2.size(); i++){
            if (s[i] != s2[i]){
                isOk = false;
                break;
            }
        }
        if (isOk) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
}
