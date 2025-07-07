#include <iostream>

using namespace std;

int main(){
    int doors;
    int first;
    
    cin >> doors;
    cin >> first;
    
    if(doors > 5) cout << "Love is open door";
    
    else{
        first = first == 0 ? 1 : 0;
        for(int i = 1; i < doors; i++){
            cout << first << endl;
            first = first == 0 ? 1 : 0;
        }  
    }
} 