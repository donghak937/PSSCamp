#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> last(26, -1); 
    vector<int> ans;
    ans.reserve(s.size());

    for (int i = 0; i < (int)s.size(); i++) {
        int idx = s[i] - 'a';
        if (last[idx] == -1) ans.push_back(-1);
        else ans.push_back(i - last[idx]);

        last[idx] = i;
    }
    return ans;
}
