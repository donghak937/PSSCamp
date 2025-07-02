#include <iostream>

using namespace std;

int main(){
    int M = 0;
    int Y = 0;
    int N;
    int time;
    int tmp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> time;

        tmp = time / 30;
        tmp++;
        Y += tmp * 10;
        
        tmp = time / 60;
        tmp++;
        M += tmp * 15;

    }
    if (Y == M) cout << "Y M " << M;
    else{
        cout << ((Y > M) ? "M " : "Y ");
        cout << ((Y > M) ? M : Y);
    }

}