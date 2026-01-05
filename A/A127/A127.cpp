#include <iostream>

using namespace std;

int main() {
	int c;
    cin >> c;

    for(int i = 0; i < c; i ++){
        int n, m;
        cin >> n >> m;

        int a = 1;

        if (n > m){
            for(int i = n*m; i >= n; i--){
                if (i % m == 0 && i % n == 0) a = i;
            }
        }
        else{
            for(int i = n*m; i >= m; i--){
                if (i % m == 0 && i % n == 0) a = i;
            }
        }
        cout << a << '\n';
    }
}