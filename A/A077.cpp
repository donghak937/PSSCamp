#include<iostream>
#include <algorithm>
#include <vector>
  
using namespace std;
  
int main() {

    vector<int> a;
    int total = 0;
    for(int i = 0; i < 8; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    vector<int> b(a);
    sort(b.begin(), b.end());

    for(int i = 3; i < 8; i++){
        total += b[i];
    }
    cout << total << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 3; j < 8; j++){
            if (a[i] == b[j]){
                cout << i+1 << " ";
            }
        }
    }

}