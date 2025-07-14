#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
  
int main() {
    vector<vector<int>> boxTypes = {{1,3},{5,5},{2,5},{4,2},{4,1},{3,1},{2,2},{1,3},{2,5},{3,2}};
    sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    int truckSize = 35;
    int count = 0;
    int total = 0;
    int i = 0;
    bool isOK = true;
    for(i = 0; i < boxTypes.size(); i++){
        cout << "i: " << i << ", box count: " << boxTypes[i][0] << ", box value: " << boxTypes[i][1] << ", current count: " << count << ", total: " << total << endl;
        if (boxTypes[i][0] + count <= truckSize){
            total += boxTypes[i][0] * boxTypes[i][1];
            count += boxTypes[i][0];
        }
        else {
            isOK = false;
            break;
        }
    }
    if (!isOK){
        int a = truckSize - count;
        cout << "Partial box count (a): " << a << ", box value: " << boxTypes[i][1] << endl;
        total += a * boxTypes[i][1];
    }



    cout << total;
}
