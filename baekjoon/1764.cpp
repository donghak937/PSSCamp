#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<string> sets;
    set<string> answer;
    

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        sets.insert(s);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        auto itr = sets.find(s);
        if(itr != sets.end()) answer.insert(s);
    }
    cout << answer.size() << '\n';
    for(string name : answer){
        cout << name << '\n';
        
    }
}