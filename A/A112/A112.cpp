#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> six;
    vector<int> one;
    for(int i = 0; i < M; i++){
        int lines, ones;
        pair<int, int> a;
        cin >> lines >> ones;
        six.push_back(lines);
        one.push_back(ones);
    }
    sort(six.begin(), six.end());
    sort(one.begin(), one.end());

    int total = 0;
    int total_cost = 0;
    while (total <= N){
        if (N - total >= 6){
            if (six[0] < one[0] * 6 ){
                total_cost += six[0];
            } 
            else{
                total_cost = total_cost + one[0] * 6;
            }
            total += 6;
        }
        else{
            if (six[0] < one[0] * (N - total) ){
                total_cost += six[0];
                total += 6;
            } 
            else{
                total_cost = total_cost + one[0] * (N - total);
                break;
            }
        }
    }
    cout << total_cost << endl;
}