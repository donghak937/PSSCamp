#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num;
    vector<char> answer;
    vector<int> s;
    int c = 1;
    for(int i = 0; i < n; i++){
        int n;
        cin >> n;
        num.push_back(n);
    }

    for(int i = 0; i < n; i++){
        if (num[i] == c){
            answer.push_back('+');
            answer.push_back('-');
            c++;
        }
        else if (num[i] > c){
            for(c; c <= num[i]; c++){
                answer.push_back('+');
                s.push_back(c);
            }
        }
        if (!s.empty() && num[i] == s.back()){
            answer.push_back('-');
            s.pop_back();
        }
    }

    if (!s.empty()) {
        cout << "NO";
    }
    else{
        for (char op : answer) {
            cout << op << '\n';
        }
    }
}