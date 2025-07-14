#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

//a.push_back({age, name});

using namespace std;
  
int main() {
    vector<string> a = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<pair<int, string>> num;
    int start;
    int end;
    cin >> start >> end;

    for(int i = start; i <= end; i++){
        string s = to_string(i);
        string l = "";
        for(char c : s){
            l += a[c - '0'];
        }
        num.push_back({i, l});
    }
    sort(num.begin(), num.end(), [] (const pair<int, string>& a, const pair<int, string>& b){
        return a.second < b.second;
    });

    for (const auto& p : num) {
        cout << p.first << " ";
    }
}
