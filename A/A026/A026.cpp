#include <iostream>
#include <string>

using namespace std;

int main(){
    int x = 10;
    bool answer = true;
    int total = 0;
    string a = to_string(x);
    for(int i = 0; i < a.size(); i++){
        total += a[i] - '0';
    }
    return x % total == 0 ? true : false;
}