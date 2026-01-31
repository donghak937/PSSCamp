#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0, maxH = 0;

    for (const auto& s : sizes) {
        int w = s[0], h = s[1];
        if (w < h) swap(w, h);  

        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }

    return maxW * maxH;
}
