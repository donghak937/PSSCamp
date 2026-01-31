#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i = 0, j = 0;

    for (const string& w : goal) {
        if (i < (int)cards1.size() && cards1[i] == w) {
            i++;
        } else if (j < (int)cards2.size() && cards2[j] == w) {
            j++;
        } else {
            return "No";
        }
    }
    return "Yes";
}
