#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n = 5, m = 2; 
    vector<int> section = {1, 4, 5};
    int answer = 0;
    int current = 0;

    for(int i = 0; i < section.size(); i++){
        if (current >= section[i]) continue;
        else{
            current = section[i] + m - 1;
            answer++;
        }
    }

    cout << answer;
}
