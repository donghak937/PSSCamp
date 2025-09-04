#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isnum(string num){
    for(char a : num){
        if(!isdigit(a)) return false;
    }
    return true;
}

int main(){
    string a, b, c;
    int n;

    cin >> a >> b >> c;

    if (isnum(a)) n = stoi(a) + 3;
    else if (isnum(b)) n = stoi(b) + 2;
    else if (isnum(c)) n = stoi(c) + 1;

    if (n % 3 == 0 && n % 5 == 0) cout << "FizzBuzz";
    else if (n % 3 == 0) cout << "Fizz";
    else if (n % 5 == 0) cout << "Buzz";
    else cout << n;
}