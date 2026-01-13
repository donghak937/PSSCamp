#include <iostream>
#include <string>

using namespace std;

int main() {

  string s;
  getline(cin, s);

  string word;
  getline(cin, word);

  size_t pos = 0;
  int count = 0;
  while (pos != string::npos) {
    pos = s.find(word);
    if (pos != string::npos) {
      count++;
      s.replace(pos, word.size(), "##");
    }
  }
  cout << count;
}
