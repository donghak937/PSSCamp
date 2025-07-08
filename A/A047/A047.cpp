#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;

    cin >> a;
    int i = 0;
    if (a.size() < 10){
        cout << a;
    }
    else{
        for(i = 0; i < a.size(); i += 10){
            cout << a.substr(i, 10) << endl;
        }
        for(i; i < a.size(); i++){
            cout << a[i];
        }
    }
}
