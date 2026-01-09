#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long> seg;

void update(int node, int start, int end, int idx) {
    if (start == end) {
        seg[node] += 1;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid)
        update(node * 2, start, mid, idx);
    else
        update(node * 2 + 1, mid + 1, end, idx);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return seg[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<pair<int, int>> roads;
        roads.reserve(K);

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            roads.push_back({ a, b });
        }

        // a 오름차순, b 오름차순
        sort(roads.begin(), roads.end());

        seg.assign(4 * M, 0);

        long long ans = 0;

        for (auto [a, b] : roads) {
            ans += query(1, 1, M, b + 1, M);

            // 현재 b 등록
            update(1, 1, M, b);
        }

        cout << "Test case " << tc << ": " << ans << "\n";
    }

    return 0;
}
