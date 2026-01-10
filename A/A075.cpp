#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comps(int a, int b){
    string a2 = to_string(a);
    string b2 = to_string(b);
    return a2 + b2 > b2 + a2;
}

int main (){
    vector<int> numbers = {0,0,0,0};
    string answer = "";

    sort(numbers.begin(), numbers.end(), comps);

    for (int num : numbers) {
        
        answer += to_string(num);
    }
    if (answer[0] == '0') answer = "0";
    cout << answer;
}