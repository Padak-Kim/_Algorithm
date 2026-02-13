#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int W = (int)weak.size();

    vector<int> w(2 * W);
    for (int i = 0; i < W; i++) {
        w[i] = weak[i];
        w[i + W] = weak[i] + n;
    }

    sort(dist.begin(), dist.end());
    int ans = INT_MAX;

    while (true) {
        for (int s = 0; s < W; s++) {
            int used = 1;
            int coverEnd = w[s] + dist[0];

            for (int idx = s; idx < s + W; idx++) {
                if (w[idx] <= coverEnd) continue;
                used++;
                if (used > (int)dist.size()) break;
                coverEnd = w[idx] + dist[used - 1];
            }

            if (used <= (int)dist.size()) ans = min(ans, used);
        }

        if (!next_permutation(dist.begin(), dist.end())) break;
    }

    return (ans == INT_MAX) ? -1 : ans;
}