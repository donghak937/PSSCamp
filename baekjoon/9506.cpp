#include <iostream>
#include <vector>

using namespace std;

int main() {
    while(true){
        int a; 
        int total = 0;
        vector<int> n;
        cin >> a;

        if (a == -1) break;
        
        for(int i = 1; i <= a / 2; i++){
            if (a % i == 0){
                n.push_back(i);
                total += i;
            }
        }
        if (total != a)  cout << a << " is NOT perfect." << "\n";
        else{
            cout << a << " = ";
            for(int i = 0; i < n.size() ; i++){
                if (i == n.size() - 1) cout << n[i] << endl;
                else cout << n[i] << " + "; 
            } 
        }
    }
}