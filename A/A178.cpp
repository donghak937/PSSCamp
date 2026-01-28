#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    map<string, int> pocket;
    map<int, string> nums;
    for(int i = 1; i <= n; i++){
        string a;
        cin >> a;
        pocket.insert({a, i});
        nums.insert({i, a});
    }

    for(int i = 0; i < m; i++){
        string b;
        cin >> b;

        if (isdigit(b[0])) {
            int c = stoi(b);
            cout << nums[c] << '\n';
        }
        else cout << pocket[b] << '\n';
    }
}