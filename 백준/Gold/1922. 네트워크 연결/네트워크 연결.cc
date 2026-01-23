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
using namespace std;
vector<int> parent;

struct Edge
{
    int u; 
    int v;
    int w;

    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};
int find(int x)
{
    if (parent[x] == x) 
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b) return;

    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ a, b, c });
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalCost = 0;
    for (auto& e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            unite(e.u, e.v);
            totalCost += e.w;
        }
    }

    cout << totalCost << "\n";
    return 0;
}