#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string expr;
    cin >> expr;

    vector<double> val(N);
    for (int i = 0; i < N; i++) cin >> val[i];

    stack<double> st;

    for (char c : expr) {
        if ('A' <= c && c <= 'Z') {
            st.push(val[c - 'A']);
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }

    cout << fixed << setprecision(2) << st.top() << "\n";
    return 0;
}
