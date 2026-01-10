#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    queue<int> q;
    string cmd;
    int x;

    while (N--) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (cmd == "size") cout << q.size() << '\n';
        else if (cmd == "empty") cout << (q.empty() ? 1 : 0) << '\n';
        else if (cmd == "front") cout << (q.empty() ? -1 : q.front()) << '\n';
        else if (cmd == "back") cout << (q.empty() ? -1 : q.back()) << '\n';

    }
}
