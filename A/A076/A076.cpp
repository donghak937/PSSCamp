#include<iostream>
#include <algorithm>
#include <vector>
  
using namespace std;
  
bool comps(string a, string b){
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}
  
int main(int argc, char** argv)
{
    int test_case;
    int T;
  
    cin>>T;
  
    for(test_case = 1; test_case <= T; ++test_case)
    {
         
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<string> a;
        int N;
        cin >> N;
          
        for(int i = 0; i < N; i++){
            string tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
          
        sort(a.begin(), a.end(), comps);
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << "#" << test_case << "\n";
        for(string s : a){
            cout << s << "\n";
        }
          
    }
    return 0;
}