#include <iostream>

using namespace std;

int main(){
    int days;
    int first;

    double a1, a2, a3, a4;
    double good, bad;
    
    cin >> days >> first;

    cin >> a1 >> a2 >> a3 >> a4;
    
    if (first == 0){
        good = a1;
        bad = a2;
    }
    else{
        good = a3;
        bad = a4;
    }

    for(int i = 1; i < days; i++){
        double new_good = good * a1 + bad * a3;
        double new_bad = good * a2 + bad * a4;
        good = new_good;
        bad = new_bad;
    }


    cout << fixed;
	cout.precision(0);

    cout << good * 1000 << endl << bad * 1000; 
} 