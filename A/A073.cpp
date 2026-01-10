#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n = 100;
    vector<string> a;
    for(int i = 1; i <= n; i++){
        if (i % 3 == 0 && i % 5 == 0){
            a.push_back("FizzBuzz");
        }
        else if (i % 3 ==0){
            a.push_back("Fizz");
        }
        else if (i % 5 ==0){
            a.push_back("Buzz");
        }
        else a.push_back(to_string(i));
    }

}
