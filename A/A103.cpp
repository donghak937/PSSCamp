#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    vector<string> words = {"gin","zen","gig","msg"};

    vector<string> moss = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    vector<string> answer;
    for(string a : words){
        string c = "";
        for(char ch : a){
            c += moss[ch - 'a'];
        }
        answer.push_back(c);
    }
    unordered_set<string> s(answer.begin(), answer.end());
    return s.size();
}
