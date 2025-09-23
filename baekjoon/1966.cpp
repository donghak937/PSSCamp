#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;
    for(int i = 0; i < size; i ++){
        int n, m;
        cin >> n >> m;
        int saved = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            q.push({j, a});
            pq.push(a);
        }

        while (!pq.empty()) {
            int t = q.front().first;
            int y = q.front().second;
            q.pop();
            if (pq.top() == y){
                saved++;
                pq.pop();
                if(t == m){
                    cout << saved << '\n';
                    break;
                }
            }
            else q.push({t, y});
        }
        
    }
}