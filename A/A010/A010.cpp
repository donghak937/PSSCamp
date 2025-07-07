#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string s = "xababcdcdababcdcd";

    int answer = s.size();
    int count = 1;
    int number = 1;
    string tmp;
    string s2 = "";

    for(int i = 0; i < s.size() / 2; i++){
        count = 1;
        tmp = s.substr(0, number);
        for(int j = number; j < s.size(); j += number){   
            if (s.substr(j, number) == tmp){
                count++;
                if (j + number >= s.size()){
                    if (count != 1){
                        s2 += to_string(count);
                    }
                    s2 += tmp;
                    count = 1;
                }
            }
            else{
                if (count != 1){
                    s2 += to_string(count);
                }
                s2 += tmp;
                count = 1;
                if (j + number >= s.size()){
                    for(int k = j; k < s.size(); k++){
                        s2 += s[k];
                    }
                    break;
                }
                else{
                    tmp = s.substr(j, number);
                }
            }
            
        }
        if(answer > s2.size()) answer = s2.size();
        number++;
        s2 = "";
    }
    cout << answer;   
}


