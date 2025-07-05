#include <iostream>

using namespace std;

int main(){
    int N;
    int floor;
    int room;

    int a[15][15] = {0};

    for(int i = 0; i < 15; i++){
        a[0][i] = i;
        a[i][0] = 0;
    }
    

    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            a[i][j] = a[i][j - 1] + a[i - 1][j];
        }
    }


    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> floor >> room;

        cout << a[floor][room] << endl;
    }

    


} 