#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> total(size, 0);
    string a;
    
    for (int count = 0; count < size; count++) {
        cin >> a;

        int cons = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'O') {
                total[count] += (1 + cons);
                cons++;
            } 
            else cons = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << total[i] << '\n';
    }

    return 0;
}
