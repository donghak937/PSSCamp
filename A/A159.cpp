#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    vector<string> wallpaper = {"..", "#."};
    vector<int> answer;

    int x1 = 99, y1 = 99, x2 = 0, y2 = 0;

    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[0].size(); j++){
            if (wallpaper[i][j] == '#'){
                if(i < x1) x1 = i; 
                if(i > x2) x2 = i; 
                if(j < y1) y1 = j; 
                if(j > y2) y2 = j; 
            }

        }
    }

    answer.push_back(x1);
    answer.push_back(y1);
    answer.push_back(x2+1);
    answer.push_back(y2+1);

    
}
