#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int graph[1001][1001];
int n, v, point;

void dfs(int point);
 
int main() {
    
    cin >> n >> v >> point;

    for(int i = 0; i < v; i++){
        int start;
        int end;

        cin >> start >> end;

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    dfs(point);
    //bfs(point);

}

void dfs(int point){

    int visit[1001] = {0};
    stack<int> s;

    s.push(point);
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        if (visit[a] == 1) continue;
        else cout << a << " ";
        visit[a] = 1;

        for(int i = n; i >= 1; i--){
            if (graph[a][i] == 1 && visit[i] == 0){
                s.push(i);
            }
        }
    }
    cout << '\n';
}

void bfs(int point){

    int visit[1001] = {0};
    queue<int> s;

    s.push(point);
    while (!s.empty()) {

    }
    cout << '\n';
}