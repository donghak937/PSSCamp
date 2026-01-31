#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> press(26, 1000000000);

    for (string km : keymap) {
        for (int i = 0; i < (int)km.size(); i++) {
            int idx = km[i] - 'A';
            press[idx] = min(press[idx], i + 1);
        }
    }

    vector<int> ans;
    for (string t : targets) {
        int sum = 0;
        bool ok = true;

        for (char c : t) {
            int idx = c - 'A';
            if (press[idx] == 1000000000) {
                ok = false;
                break;
            }
            sum += press[idx];
        }

        ans.push_back(ok ? sum : -1);
    }

    return ans;
}
