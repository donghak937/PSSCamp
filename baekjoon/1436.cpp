#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;


    for(int i = 666; i < 100000001; i++){
        string a = to_string(i);

        if(a.find("666") != string::npos) count++;
        if (count == n){
            cout << i;
            return 0;
        }
    }
}