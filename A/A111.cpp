#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int how;
        cin >> how;
        double people = 1;
        for(int j = 1; j < how; j++){
            people = (people + 0.5) * 2;
        }
        
        cout << (int)people << endl; 
    }
}