#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct Edge {
	int u;
	int v;
	int cost;

	bool operator< (const Edge& e) const {
		return cost < e.cost;
	}
};

struct DSU {
	vector<int> parent, rank;
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] < rank[v]) {
			parent[u] = v;
		}
		else {
			parent[v] = u;
			if (rank[u] == rank[v]) rank[u]++;
		}
	}

	bool same(int u, int v) {
		return find(u) == find(v);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M; // 집의 개수, 길의 개수
	cin >> N >> M;

	vector<Edge> edges;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; // a번 집과 b번 집을 잇는 길의 유지비 c
		cin >> a >> b >> c;

		edges.push_back({ a, b, c });
	}

	sort(edges.begin(), edges.end());
	DSU dsu(N + 1);
	int totalCost = 0;
	int picked = 0;
	int lastCost = 0;
	for (auto& e : edges) {
		if (!dsu.same(e.u, e.v))
		{
			dsu.merge(e.u, e.v);
			totalCost += e.cost;
			lastCost = e.cost;
		}
	}
	cout << totalCost - lastCost << "\n";
	return 0;
}