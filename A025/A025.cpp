#include <iostream>

using namespace std;

int main(){
    int n = 16;
    int n2 = 0;
    if (n == 0) return false;
    while (true){
        if (n == 1) return true;
        else if (n2 != 0) return false;
        
        n2 = n % 4;
        n = n / 4 + n2;
    }
}