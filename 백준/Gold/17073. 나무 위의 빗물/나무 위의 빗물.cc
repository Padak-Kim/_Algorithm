#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, w;

vector<vector<int>> graph;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (graph[i].size() == 1) cnt++;
    }

    long double res = (long double)w / cnt;

    cout << fixed << setprecision(10) << res;
    return 0;
}