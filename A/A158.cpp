#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {

    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
    vector<string> callings = {"kai", "kai", "mine", "mine"};

    unordered_map<string, int> pos;

    for (int i = 0; i < (int)players.size(); i++) {
        pos[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++){
        
        int idx = pos[callings[i]];
        
        auto it  = players.begin() + idx;
        auto it2 = it - 1;
        
        string frontName = *it2;
        string curName   = *it;

        iter_swap(it, it2);

        pos[curName] = idx - 1;
        pos[frontName] = idx;
    }


}

