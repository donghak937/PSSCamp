#include <iostream>

using namespace std;

int main() {
    
    int N;
    string str;
    cin >> N;
    cin >> str;
    bool isOk = true;
    string pre;
    string fore;

    for(int i = 0; i < str.size(); i++){
        if (str[i] == '*')isOk = false;
        else if (isOk) pre += str[i];
        else fore += str[i];
    }

    for(int i = 0; i < N; i++){
        string a;
        cin >> a;
        if (a.size() < pre.size() || a.size() < fore.size()) cout << "NE" << endl;
        else if (a.substr(0, pre.size()) == pre && a.substr(a.size() - fore.size(), fore.size()) == fore) cout << "DA" << endl;
        else cout << "NE" << endl;
    }

}