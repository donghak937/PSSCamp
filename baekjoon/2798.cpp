#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    vector<int> card;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int a; 
        cin >> a;
        card.push_back(a);
    }
    int max = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if (i == j) continue;
            for(int k = 0; k < N; k++){
                if (k == i || k == j) continue;
                sum = card[i] + card[j]+ card[k];
                if ((M - sum) >= 0 && max < sum) max = sum;
            }
        }
    }

    cout << max;
}