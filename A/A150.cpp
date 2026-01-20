#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    int now;
    int maxi;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if (!i){
            now = a;
            maxi = a;
        }

        else{
            now = max(a, now + a);
            maxi = max(now, maxi);
        }


    }

    cout << maxi;
}
   