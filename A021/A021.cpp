#include <iostream>

using namespace std;

int main(){
    int N;
    int mult;
    int answer = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> mult;
        answer += mult;
    }
    cout << answer - (N - 1);
}