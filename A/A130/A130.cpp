#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> a;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (tmp == 0) a.pop();
        else a.push(tmp);
    }

    int sum = 0;
    while (!a.empty()) {
        sum += a.top();
        a.pop();
    }
    cout << sum << endl;
    
}