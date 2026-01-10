#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> cookie = {1,2,1,2};

    int bro = 0;
    int lilbro = 0;
    
    int M;
    int C;

    int max = 0;

    for(int i = 0; i < cookie.size() - 1; i++){
        M = i;
        C = M + 1;
        bro = cookie[M];
        lilbro = cookie[C];
        while (true){
            if ((lilbro == bro) && max <= bro){
                max = bro;
            }
            else if ((bro <= lilbro) && M != 0){
                M--;
                bro += cookie[M];
            }
            else if ((bro >= lilbro) && C != cookie.size() -1 ){
                C++;
                lilbro += cookie[C];
            }
            else{
                break;
            }
        }
    }
    cout << max;

}