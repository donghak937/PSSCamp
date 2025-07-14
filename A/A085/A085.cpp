#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool coms(string a, string b){
    if (a.size() == b.size()){
        int sumA = 0, sumB = 0;
        for (char c : a) if (isdigit(c)) sumA += c - '0';
        for (char c : b) if (isdigit(c)) sumB += c - '0';
        if (sumA == sumB){
            return a < b;
        }
        return sumA > sumB;
    }
    return a.size() < b.size();

}
  
int main() {
    
    int N;
    vector<string> a;
    cin >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), coms);
    for (const auto& s : a) {
        cout << s << '\n';
    }

}
