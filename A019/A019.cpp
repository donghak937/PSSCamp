#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int num1;
    int num2;
    int num3;

    int b;

    int a[10] = {0,};

    string c;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    b = num1 * num2 * num3;
    c = to_string(b);

    for(int i = 0; i < c.size(); i++){
        a[c[i] - '0']++;
    }

    for(int i = 0; i < 10; i++){
        cout << a[i] << endl;
    }

}