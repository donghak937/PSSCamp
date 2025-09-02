#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0 ; i < n; i++){
        string a;
        string num;
        vector<string> b;
        long long answer;
        getline(cin, a);
        for(int j = 0; j < a.size(); j++){
            if(a[j] == ' ') continue;
            else if (a[j] == '-' && isdigit(a[j + 1]) && j != a.size()- 1){
                num += a[j];

            }
            else if (!isdigit(a[j]) || a[j] == '-'){
                b.push_back(num);
                num = "";
            }
            else {
                num += a[j];
            }
        }
        
        b.push_back(num);

        if (a[b[0].size() + 1] == '+') answer = stoll(b[0]) + stoll(b[1]);
        else if (a[b[0].size() + 1] == '-') answer = stoll(b[0]) - stoll(b[1]);
        else if (a[b[0].size() + 1] == '/') answer = stoll(b[0]) / stoll(b[1]);
        else if (a[b[0].size() + 1] == '*') answer = stoll(b[0]) * stoll(b[1]);

        if (answer == stoll(b[2])) cout << "correct" << endl;
        else cout << "wrong answer" << endl;
        
    }
}