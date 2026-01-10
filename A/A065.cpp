#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    for (const auto& p : a) {
        cout << p.first << " " << p.second << '\n';
    }
}
