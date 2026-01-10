#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> c;
    int i = 1;
    int count = 0;
    while (true) {
        for(int k = 0; k < i; k++){
            c.push_back(i);
            count++;
        }
        i++;
        if (count >= 1000) break;
    }
    int n, m;
    int total = 0;
    cin >> n >> m;
    for(int j = n- 1; j < m; j++){
        total += c[j];
    }
    cout << total;
    
}
