#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string word = "abcdefd";
    char ch = 'd';
    for(int i = 0; i < word.size(); i++){
        if (word[i] == ch){
            reverse(word.begin(), word.begin() + i+1);
            break;
        }
    }
    cout << word;
}