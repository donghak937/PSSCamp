#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    vector<long long> dis;
    vector<long long> costs;

    long long total = 0;
    long long distan = 0;

    cin >> n;

    for(long long i = 0; i < n - 1; i++){
        long long a;
        cin >> a;
        dis.push_back(a);
    }

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        costs.push_back(a);
    }

    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            distan += dis[j-1];
            if (costs[i] > costs[j] || j == n - 1){
                total += distan * costs[i];
                distan = 0;
                i = j-1;
                break;
            }
        }
    }

    cout << total;


    

}