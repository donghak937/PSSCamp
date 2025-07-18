#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> answer;
    for(int i = 0; i < matrix[0].size(); i++){
        vector<int> tmp;
        for(int j = 0; j < matrix.size(); j++){
            tmp.push_back(matrix[j][i]);
        }
        answer.push_back(tmp);
    }

    for(const auto& row : answer) {
        for(const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
