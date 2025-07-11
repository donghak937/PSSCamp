#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  int K;
  int count = -1;
  vector<int> a;
  cin >> N >> K;
  for(int i = 1; i <= N; i++){
    a.push_back(i);
  }
  cout << "<";
  while(a.size() != 1){
    count += K;
    if (count >= a.size()) count %= a.size();

    cout << a[count] << ", ";
    a.erase(a.begin() + count);
    count--;
  }
    cout << a[0] << ">";

}
