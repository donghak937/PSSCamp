#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<vector<int>> arr1 = {{1,2},{2,3}};
    vector<vector<int>> arr2 = {{3,4},{5,6}};
    for(int i = 0; i < arr1.size(); i++){
        for(int j =0; j < arr1[0].size(); j++){
            arr1[i][j] += arr2[i][j];
        }
    }
    //return arr1;


}