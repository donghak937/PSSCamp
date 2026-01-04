#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, total;
    vector<int> coins;

    cin >> n >> total;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    int how = coins.size() - 1;
    int answer = 0;

    while(total != 0){
        if (total / coins[how] == 0){
            how--;
        }
        else{
            answer += total / coins[how];
            total %= coins[how];
        }
    }

    cout << answer;
    

}