#include <iostream>

using namespace std;

int main() {
    int N;
    int count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        bool isOk = true;
        int n;
        cin >> n;
        if (n == 0 || n == 1) continue;
        else{
            for(int i = 2; i < n; i++){
                if (n % i == 0){
                    isOk = false;
                    break;
                }
            }
            if (isOk) count++;
        }
    }
    cout << count;
}