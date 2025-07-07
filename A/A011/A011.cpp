#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

static bool comp(pair<int, double>& a, pair<int, double>& b){
    if (a.second == b.second){
        return a.first < b.first;
    }
	return a.second > b.second;
}

int main(){
    int N = 2;
    vector<int> stages = {1, 1, 1, 1};
    vector<int> answer;
    double averge = 0;
    map<int, double> ang;
    int size = stages.size();
    for(int i = 1; i <= N; i++){
        int cnt = count(stages.begin(), stages.end(), i);
        if (cnt == 0){
            averge = 0;
        }
        else {
            averge = (double)cnt / (double)size;
        } 
        ang.insert({i, averge});
        size -= cnt; 
    }

    vector<pair<int, double>> v(ang.begin(), ang.end());
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < N; i++){
        answer.push_back(v[i].first);
        cout << v[i].first << endl;
    }
}


