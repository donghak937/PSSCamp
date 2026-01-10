#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string a;
    int trys;
    bool isOk = true;
    int total = 0;
    
    cin >> trys;
    for (int i = 0; i < trys; i++) {
        cin >> a;

        char letter = ' ';
        unordered_set<char> seen;

        for (char c : a) {
            if (c != letter){
                if (seen.count(c)){
                    isOk = false;
                    break;
                }
                seen.insert(c);
            }
            letter = c;
        }
        if (isOk) total++;
        isOk = true;
    }

    cout << total;
}
