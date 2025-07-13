#include <iostream>
#include <algorithm>
#include <vector>
  
using namespace std;
  
int main() {
    vector<int> citations = {5, 6, 7, 8};
    int hcount = 0;
    int count = 0;
    int max = 0;
    for(int i = 0; i <= citations[citations.size() - 1]; i++){
        for(int j = 0; j < citations.size(); j++){
            if (i <= citations[j]) {
                cout << " i " << i << " j " << citations[j] << endl;
                hcount++;
            }
            else count++;
        }
        
        cout << " hcount " << hcount << " count " << count << endl;
        if (i <= hcount){
            max = i;
        }
        hcount = 0;
        count = 0;
    }
    cout << max;

}