#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int num = 38;
    string c = to_string(num);
    int tmp = 0;

    while (c.size() != 1){
        for(int i = 0; i < c.size(); i++){
            tmp += c[i] - '0';
        }
        c = to_string(tmp);
        tmp = 0;
    }
    cout << stoi(c);

}