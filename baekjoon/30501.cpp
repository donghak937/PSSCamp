#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(char c : s){
            if (c =='S'){
                cout << s;
                break;
            }
        }
    }
}