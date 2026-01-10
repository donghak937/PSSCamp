#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    double aver = 0;
    int mid;
    vector<int> a;
    unordered_map<int,int> freq;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        int b;
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());


    for (int x : a) {
        freq[x]++;
    }

    int mode = a[0];
    int max = 0;

    for(auto &p : freq){
        if (p.second > max) {
            max = p.second;
            mode = p.first;
        }
    }
    
    vector<int> modes;

    for(auto &p : freq){
        if (p.second == max) {
            modes.push_back(p.first);
        }
    }

    sort(modes.begin(), modes.end());

    if(modes.size() >= 2) mode = modes[1];


    for(int i = 0 ; i < N; i++){
        aver += a[i];
    }
    aver /= N;
    aver = round(aver);
    mid = N / 2;
    int range = 0;
    if (a.size() == 1) range = 0;
    else if (a[0] * a[a.size() - 1] < 0){
        range = abs(a[0]) + a[a.size() - 1];
    }
    else{
        range = abs(a[a.size() - 1] - a[0]);
    }

    cout << (int)aver << '\n';
    cout << a[mid] << '\n';
    cout << mode << '\n';
    cout <<  range << '\n';
    
}