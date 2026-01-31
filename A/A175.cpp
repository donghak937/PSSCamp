#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    vector<string> say = {"aya", "ye", "woo", "ma"};
    int answer = 0;

    for (const string& w : babbling) {
        int i = 0;
        int last = -1;   
        bool ok = true;

        while (i < (int)w.size()) {
            bool matched = false;

            for (int s = 0; s < 4; s++) {
                const string& p = say[s];

                if (i + (int)p.size() <= (int)w.size() &&
                    w.compare(i, p.size(), p) == 0) {

                    if (last == s) {
                        ok = false;
                    } else {
                        last = s;
                        i += (int)p.size();
                        matched = true;
                    }
                    break;
                }
            }

            if (!ok) break;
            if (!matched) { 
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    return answer;
}