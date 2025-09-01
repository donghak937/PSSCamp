#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> num;
    num.push_back(a);
    num.push_back(b);
    num.push_back(c);

    sort(num.begin(), num.end(), greater<int>());

    while(num[1] + num[2] <= num[0]) num[0]--;

    cout << num[0] + num[1] + num[2];

}