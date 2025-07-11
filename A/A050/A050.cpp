#include <iostream>
#include <string>

using namespace std;

int main() {
    string code = "DEFGHIJKLMNOPQRSTUVWXYZABC";
    string code2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string input;
    string answer = "";
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        int num = code.find(input[i]);
        answer += code2[num];
    }
    cout << answer;
}
