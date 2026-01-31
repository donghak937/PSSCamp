#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string b = "";
    for (int i = 0; i < t.size(); i++) {
        if (i + p.size()-1 == t.size()) break;
        else {
            for (int j = i; j < p.size() + i; j++) {
                b += t[j];
            }
            if (stoul(b) <= stoul(p)) answer++;
            b = "";
        }
    }
    return answer;
}