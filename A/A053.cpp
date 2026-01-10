#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> a;
    int size;
    string input;
    int tmp;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> input;
        if (input == "push"){
            cin >> tmp;
            a.push(tmp);
        }
        else if (input == "top"){
            if (a.empty()) cout << "-1" << endl;
            else cout << a.top() << endl;
        }
        else if (input == "size"){
            cout << a.size() << endl;
        }
        else if (input == "empty"){
            if (a.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (input == "pop"){
            if (a.empty()) cout << "-1" << endl;
            else {
                cout << a.top() << endl;
                a.pop();
            }
        }
    }
}
