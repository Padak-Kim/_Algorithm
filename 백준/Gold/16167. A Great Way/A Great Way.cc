#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

int N, R;
vector<pair<int, int>> graph[100001]; // {v, w}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R;

    for (int i = 0; i < R; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        int w = c;
        if (e > 10) w += (e - 10) * d;

        graph[a].push_back({b, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {dist, node}

    vector<int> dist(N + 1, INT_MAX);
    vector<int> cnt(N + 1, INT_MAX);

    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            int nd = dist[u] + w;
            int nc = cnt[u] + 1;

            if (nd < dist[v]) {
                dist[v] = nd;
                cnt[v] = nc;
                pq.push({dist[v], v});
            } else if (nd == dist[v] && nc < cnt[v]) {
                cnt[v] = nc;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[N] == INT_MAX)
        cout << "It is not a great way.\n";   // ✅ 오타 수정
    else
        cout << dist[N] << " " << cnt[N] << "\n";
}
