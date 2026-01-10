#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    int answer = 0;
    int start = 0;
    int end = people.size() - 1;
    sort(people.begin(), people.end());
    
    while (end > start) {
        if (people[start] + people[end] > limit){
            people[end] = 0;
            end--;
            answer++;
        }
        else{
            people[end] = 0;
            people[start] = 0;
            start++;
            end--;
            answer++;
        }
    }
    if(people[end] != 0 || people[start] != 0) answer++;
    cout << answer;
}