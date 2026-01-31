#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string s;
    getline(cin, s);

    bool inTag = false;
    string word;

    for (char c : s) {
        if (inTag) {
            cout << c;
            if (c == '>') inTag = false;
        } else {
            if (c == '<') {
                reverse(word.begin(), word.end());
                cout << word;
                word.clear();

                inTag = true;
                cout << c; 
            } 
            else if (c == ' ') {
                reverse(word.begin(), word.end());
                cout << word;
                word.clear();

                cout << ' ';
            } 
            else {
                word += c;
            }
        }
    }

    reverse(word.begin(), word.end());
    cout << word;

    return 0;
}
