#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<string> a = {  
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };

    vector<string> b = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };
    vector<string> ans;

    int x, y;
    string n;
    cin >> y >> x;

    int xStart = 0;
    int yStart = 0;

    
    int change = 1e9;
    
    for(int i = 0; i < y; i++){
        cin >> n;
        ans.push_back(n);
        
    } 
    
    while (true){
        int aAns = 0;
        int bAns = 0;

        for(int i = yStart; i < yStart + 8; i++){
            for(int j = xStart; j < xStart + 8; j++){
                if (a[i-yStart][j-xStart] != ans[i][j]) aAns++;
                if (b[i-yStart][j-xStart] != ans[i][j]) bAns++;
            } 
        }

        change = min(change, min(aAns, bAns));

        xStart++;
        if(xStart > x - 8){
            xStart = 0;
            yStart++;
        }
        if (yStart > y - 8){
            break;
        }
    }
    cout << change;
    
}