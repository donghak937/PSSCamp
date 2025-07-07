#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<vector<int>> answer;
    int count = 0;
    int temp = 0;
    int numRows = 5;
    stack<int> b;    
    while(numRows > count){
        vector<int> a;

        for(int i = 0; i < count+1; i++){
            if (i == 0){
                a.push_back(1);
            }
            else if (i == count){
                a.push_back(1);
            }
            else{
                temp += b.top();
                b.pop();
                temp += b.top();
                a.push_back(temp);
                temp = 0;
            }
        }

        for(int g = 0; g < a.size(); g++){
            b.push(a[g]);
        }
        answer.push_back(a);
        count++;
    }    
}