#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> st;
    st.reserve(ingredient.size());

    int cnt = 0;

    for (int x : ingredient) {
        st.push_back(x);

        if (st.size() >= 4) {
            int n = (int)st.size();
            if (st[n - 4] == 1 && st[n - 3] == 2 && st[n - 2] == 3 && st[n - 1] == 1) {
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.pop_back();
                cnt++;
            }
        }
    }

    return cnt;
}
