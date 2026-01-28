#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n = 8, m = 4; 
    vector<int> section = {2, 3, 6};
    int answer = 0;
    int current = section[0];

    for(int i = 0; i < section.size(); i++){
        if (current > section[i]) continue;
        else{
            current += m - 1;
            answer++;
        }
    }

    cout << answer;
}
