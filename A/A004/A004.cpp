#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> answer;
    vector<int> arr = {5,9,7,10};
    int divisor = 5;
    for(int i = 0; i < arr.size(); i++){
        if (arr[i] % divisor == 0) answer.push_back(arr[i]);
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0) answer.push_back(-1);

    printVector(answer);
    
}