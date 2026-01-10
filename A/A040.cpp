#include <iostream>
#include <string>

using namespace std;

int main(){
    string s = "book";
    string vowel = "aioeuAIOEU";
    int i = 0;
    int j = s.size() / 2;
    int icount = 0, jcount = 0;

    while(j != (s.size())){
        if (vowel.find(s[i]) != string::npos) icount++;
        if (vowel.find(s[j]) != string::npos) jcount++;
        cout << "s[i] : " << s[i] << endl;
        cout << "s[j] : " << s[j] << endl;
        cout << "-------------" << endl;
        i++;
        j++;
    }

    cout << (icount == jcount);

} 