#include <iostream>

using namespace std;

int main() {
    int N;
    int a[101][101] = {0};
    cin >> N;
    for(int i = 0; i < N; i++){
        int ver; 
        int hor;
        cin >> hor >> ver;
        for (int j = ver; ver+10 > j; j++){
            for (int k = hor; hor+10 > k; k++){
               a[j][k] = 1;
            }
        }
    }
    int count =0;
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            if (a[i][j] == 1) count++;
        }
    }
    cout << count;
}