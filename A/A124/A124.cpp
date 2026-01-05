#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    vector<int> prime;
    cin >> N;
    if (N == 1) return 0;

    for(int i = 0; i <= N; i++){
        prime.push_back(i);
    }

    for (int i = 2; i <= sqrt(N); i++){
        if (prime[i] == 0) continue;
        for (int j = i * i; j <= N; j += i){
            prime[j] = 0;
        }
    }
    prime.erase(remove(prime.begin(), prime.end(), 0), prime.end());

    for(int i = 1; i < prime.size(); i++){
        if (N % prime[i] == 0) {
            N /= prime[i];
            cout << prime[i] << endl;
            i--;
        }
    }

}