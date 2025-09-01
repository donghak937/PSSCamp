#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<char> a = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    int N;
    int B;
    string total = ""; 
    cin >> B >> N;

    while (B != 0){
        total += a[B % N];
        B /= N;
    }
    reverse(total.begin(), total.end());
    cout << total;

}