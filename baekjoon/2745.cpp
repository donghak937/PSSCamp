#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<char> a = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    int N;
    string B;
    int total = 0;
    cin >> B >> N;
    reverse(B.begin(), B.end());
    
    for(int i = 0 ; i < B.size(); i++){
        auto it = find(a.begin(), a.end(), B[i]);
        int b = distance(a.begin(), it);
        total += b * pow(N, i);
    }
    cout << total;
}