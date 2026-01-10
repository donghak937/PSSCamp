#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    stack<int> a;
    a.push(9); //stack top 오류 방지용 flag
    int k = 0;
    int answer = 0;

    for(int i = 0; i < moves.size(); i++){

        for(k = 0; k < board[0].size(); k++){
            if (board[k][moves[i] - 1] != 0){
                if (a.top() == board[k][moves[i]- 1]){
                    a.pop();
                    board[k][moves[i]- 1] = 0;
                    answer += 2;
                }
                else {
                    a.push(board[k][moves[i]- 1]);
                    board[k][moves[i]- 1] = 0;
                }
                break;
            }
        }
    }
    cout << answer;
}