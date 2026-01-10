#include <iostream>
#include <string>

using namespace std;

int main(){
    string text = "nlaebolko";
    int a = 0;
    int b = 0;
    int l = 0;
    int n = 0;
    int o = 0;
    int answer = 0;
    for(char ch : text){
        if (ch == 'b') b++;
        else if (ch == 'a') a++;
        else if (ch == 'l') l++;
        else if (ch == 'o') o++;
        else if (ch == 'n') n++;
    }
    while (true) {
        b--;
        if (b < 0) break;
        a--; 
        if (a < 0) break;
        l -= 2; 
        if (l < 0) break;
        o -= 2; 
        if (o < 0) break;
        n--; 
        if (n < 0) break;
        answer++;
    }
    cout << answer;

}