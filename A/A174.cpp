#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> pq; 
    vector<int> ans;
    ans.reserve(score.size());

    for (int s : score) {
        pq.push(s);
        if ((int)pq.size() > k) pq.pop();     
        ans.push_back(pq.top());              
    }

    return ans;
}
