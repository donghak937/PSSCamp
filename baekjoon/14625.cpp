#include <iostream>

using namespace std;

int main() {
    int start_min, start_hour;
    int end_min, end_hour;
    int n;
    int count = 0;

    cin >> start_hour >> start_min;
    cin >> end_hour >> end_min;
    cin >> n;

    while(start_hour != end_hour || start_min != end_min){
        if (start_min % 10 == n) count++;
        else if (start_min / 10 == n) count++;
        else if (start_hour % 10 == n) count++;
        else if (start_hour / 10 == n) count++;

        start_min++;
        if (start_min == 60){
            start_hour++;
            start_min = 0;
        }
    }

    if (start_min % 10 == n) count++;
    else if (start_min / 10 == n) count++;
    else if (start_hour % 10 == n) count++;
    else if (start_hour / 10 == n) count++;
    
    cout << count;

}