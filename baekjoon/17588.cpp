#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> num;
    int n;
    cin >> n;
    bool isOk = true;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }

    for(int i = 1; i <= num[num.size() -1]; i++){
        auto it = find(num.begin(), num.end(), i);
        if (it == num.end()) {
            cout << i << "\n";
            isOk = false;
        }
    }
    if(isOk) cout << "good job";
}