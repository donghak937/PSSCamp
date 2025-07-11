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
        int tmp = a.front();
        a.pop();
        a.push(tmp);
    }

    cout << a.front();
}
