#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int start = 0;
    int destination = 3;
    vector<int> distance = {1,2,3,4};
    int total = 0;
    for(int i = start; i != destination; i = (i + 1) % distance.size()){
        cout << i << " ";
        total += distance[i];
    }

    int total2 = 0;
    for(int i = start; i != destination;){
        if (i == 0) i = distance.size() - 1;
        else i--;
        cout << i << " ";
        total2 += distance[i];
    }

    cout << (total < total2 ? total : total2);
}