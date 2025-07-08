#include <iostream>
#include <string>

using namespace std;

bool sameLetter(string word){
    for(int i = 0; i < word.size() - 1; i++){
        if ((word[i] == word[i+1]) && !(word[i] == 'e' || word[i] == 'o' )){
           return false;
        }
    }
    return true;
}

bool hasVowel(string word){
    string vowel = "aeiou";
    bool isOk = false;
    for(char a : vowel){
        if (word.find(a) != string::npos) isOk = true;
    }
    return isOk;
}

bool vowel3(string word){
    string vowel = "aeiou";
    int vcount = 0;
    int ccount = 0;
    for(char a : word){
        if (vowel.find(a) != string::npos){
            vcount++;
            ccount = 0;
        }
        else{
            vcount = 0;
            ccount++;
        }
        if (vcount >= 3 || ccount >= 3){
            return false;
        }
    }
    return true; 
}

int main() {
    string input;
    
    while (true){
        cin >> input;
        if (input == "end") break;
        if (sameLetter(input) && hasVowel(input) && vowel3(input)){
            cout << "<" << input << ">" << " is acceptable." << endl;
        }
        else{
            cout << "<" << input << ">" << " is not acceptable." << endl;
        }
    }
}
