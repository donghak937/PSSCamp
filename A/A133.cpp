#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string title = "First leTTeR of EACH Word";
    vector<string> words;
    string word;
    stringstream ss(title);

    while (getline(ss, word, ' ')){
        words.push_back(word);
    }


    for(int i = 0; i < words.size(); i++){
        if (words[i].size() >= 3){
            for(int j = 0; j < words[i].size(); j++){
                words[i][j] = tolower(words[i][j]);
            }

            words[i][0] = toupper(words[i][0]);
        }
        else{
            for(int j = 0; j < words[i].size(); j++){
                words[i][j] = tolower(words[i][j]);
            }
        }
    }
    string answer = "";
    for(int i = 0; i < words.size(); i++){
        answer += words[i];
        if (i == words.size() -1) break;
        answer += " ";
    }
    for(int i = 0; i < words.size(); i++){
        cout << words[i] << " ";
    }
}