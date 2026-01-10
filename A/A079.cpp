#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
  
int main() {
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<int> answer;
    vector<int> a;
    for(int i = 0; i < commands.size(); i++){
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++){
            a.push_back(array[j]);
        }
        sort(a.begin(), a.end());
        answer.push_back(a[commands[i][2] - 1]);
        a.clear();
    }
    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;
}