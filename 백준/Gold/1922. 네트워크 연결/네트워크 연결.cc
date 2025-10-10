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

struct DSU {
	vector<int> parent, rank;

	DSU(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++){
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a == b)
			return;

		if (rank[a] < rank[b])
			swap(a, b);
		parent[b] = a;
		if (rank[a] == rank[b])
			rank[a]++;

		return;
	}

	bool same(int a, int b) {
		return find(a) == find(b);
	}
};
struct Edge {
	int u;
	int v;
	int cost;

	bool operator<(const Edge& e) const {
		return cost < e.cost;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; // 컴퓨터의 수
	cin >> n;
	int m; // 연결할 수 있는 선의 수
	cin >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
	vector<Edge> edges;
	for (int i = 0; i < m; i++){
		int a, b, c;	// a컴퓨터와 b컴퓨터를 연결하는데 비용 c (a == b 일수도 있음)
		cin >> a >> b >> c;
		graph[a][b] = c;

		edges.push_back({ a, b, c });
	}
	// 비용순으로 정렬
	sort(edges.begin(), edges.end());
	
	DSU dsu(n + 1);

	int totalCost = 0;
	for (const auto& edge : edges) {
		if (!dsu.same(edge.u, edge.v))
		{
			dsu.merge(edge.u, edge.v);
			totalCost += edge.cost;
		}
	}

	cout << totalCost << '\n';
	return 0;
}