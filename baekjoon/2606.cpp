#include <iostream>
#include <stack>

using namespace std;

int bfs(int point);

int graph[1001][1001];
int n, v;

int main() {

    cin >> n >> v;

    for(int i = 0; i < v; i++){
        int x,y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    cout << bfs(1) - 1;

}

int bfs(int point){
    stack<int> a;

    int score[1001] = {0};
    int count = 0;

    a.push(point);

    while(!a.empty()){
        int b = a.top();
        a.pop();
        if (score[b] == 1) continue;
        else{
            count++;
        }
        score[b] = 1;

        for(int i = 1 ; i <= n; i++){
            if (graph[b][i] == 1 && score[i] == 0){
                a.push(i);
            }
        }
    }
    return count;
}