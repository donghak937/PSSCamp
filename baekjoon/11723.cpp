#include <iostream>
#include <set>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    set<int> s;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        string op;
        cin >> op;

        if (op == "add"){
            int a;
            cin >> a;
            s.insert(a);
        }
        else if (op == "check"){
            int a;
            cin >> a;
            if (s.count(a)) cout << "1\n";
            else cout << "0\n";
        }
        else if (op == "remove"){
            int a;
            cin >> a;
            s.erase(a);
        }
        else if (op == "toggle"){
            int a;
            cin >> a;
            if (s.count(a)) s.erase(a);
            else s.insert(a);
        }
        else if (op == "all"){
            s.clear();
            for(int j = 1; j <= 20; j++){
                s.insert(j);
            }
        }
        else s.clear();

    }

}