#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> bills = {5,5,5,10,5,5,10,20,20,20};
    int five = 0;
    int ten = 0;
    int twenty = 0;
    bool isOk = true;

    for(int i = 0; i < bills.size(); i++){
        if (bills[i] == 5){
            five++;
        }
        else if (bills[i] == 10){
            if (five != 0){
                ten++;
                five--;
            }
            else{
                isOk = false;
            }
        }
        else if (bills[i] == 20){
            if (five == 0){
                isOk = false;
            }
            else{
                if (ten != 0){
                    ten--;
                    if (five == 0){
                        isOk = false;
                    }
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else isOk = false;
            }
        }
    }
    cout << isOk;

}