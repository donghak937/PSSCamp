#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> a;
    for(int i = 1; i <= N; i++){
        a.push(i);
    }

    while (true){
        if (a.size() == 1) break;
        a.pop();
        a.push(a.front());
        a.pop();
        
    }

    cout << a.front();
}
