#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

static int toDays(const string& date) {

    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));


    return ((y * 12) + (m - 1)) * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> termMonths;
    termMonths.reserve(terms.size() * 2);

    for (const string& t : terms) {
        int sp = (int)t.find(' ');
        string kind = t.substr(0, sp);
        int months = stoi(t.substr(sp + 1));
        termMonths[kind] = months;
    }

    int todayDay = toDays(today);
    vector<int> answer;

    for (int i = 0; i < (int)privacies.size(); i++) {
        const string& p = privacies[i];
        int sp = (int)p.find(' ');

        string date = p.substr(0, sp);
        string kind = p.substr(sp + 1);

        int startDay = toDays(date);
        int limit = startDay + termMonths[kind] * 28;

        if (todayDay >= limit) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}