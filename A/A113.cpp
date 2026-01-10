#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int node, bool visited[], vector<int> graph[]){
    visited[node] = true;
    for(int next : graph[node]){
        if(!visited[next]) dfs(next, visited, graph);
    }
}

int main() {
    int N, M;
    int count = 0;
    cin >> N >> M;
    vector<int> graph[1001];
    bool visited[1001]; 

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        vector<int> tmp;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i, visited, graph);
            count++;
        }
    }

    cout << count;

}