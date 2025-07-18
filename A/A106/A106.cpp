#include <iostream>

using namespace std;

int main() {
    string s =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N;
    cin >> N;
    for(int i =0; i < N; i++){
        string tmp;
        cin >> tmp;
        int total = 0;
        for(char ch : s){
            if (tmp.find(ch) == string::npos) total += (int)ch;
        }
        cout << total << endl;
    }
}
