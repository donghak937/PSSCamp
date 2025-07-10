#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> operations = {"5","-2","4","C","D","9","+","+"};
    vector<int> a;
    int answer = 0;
    for(int i = 0; i < operations.size(); i++){
        if (operations[i] == "C"){
            a.pop_back();
        }
        else if (operations[i] == "+"){
            int tmp = a[a.size() - 1] + a[a.size() - 2]; 
            a.push_back(tmp);
        }
        else if (operations[i] == "D"){
            int tmp = a[a.size() - 1] * 2; 
            a.push_back(tmp);
        }
        else{
            a.push_back(stoi(operations[i]));
        }
    }

}