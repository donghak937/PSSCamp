#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string tmp = " ";
    string temp = " ";
    double answer = 0;
    bool isNum = true;
    int n;

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        
        getline(cin, temp);

        for(int j = 0; j < temp.size(); j++){
            if (temp[j] == ' ' && isNum){
                answer = stod(tmp);
                isNum = false;
            }
            else if (temp[j] == '@'){
                answer *= 3;
            }
            else if (temp[j] == '%'){
                answer += 5;
                
            }
            else if (temp[j] == '#'){
                answer -= 7;
            }
            else{
                tmp += temp[j];
            }
        }

        cout << fixed << setprecision(2) << answer << endl;
        answer = 0;
        isNum = true;
        tmp = "";
    }
} 