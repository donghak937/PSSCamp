#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> a;
    string word = "EIO";

    char ch[5] = {'A', 'E', 'I', 'O', 'U'};
    string words = "";
    for(int i = 0; i < 5; i++){
        words = ch[i];
        a.push_back(words);
        for(int j = 0; j < 5; j++){
            words = {ch[i], ch[j]};
            a.push_back(words);
            for(int k = 0; k < 5; k++){
                words = {ch[i], ch[j], ch[k]};
                a.push_back(words);
                for(int c = 0; c < 5; c++){
                    words = {ch[i], ch[j], ch[k], ch[c]};
                    a.push_back(words);
                    for(int p = 0; p < 5; p++){
                        words = {ch[i], ch[j], ch[k], ch[c], ch[p]};
                        a.push_back(words);
                    }
                }
            }
        }
    }
    for(int i = 0; i < a.size(); i++){
        if (a[i] == word) cout << i+1;
    }

}