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

	DSU(int n) : parent(n), rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u])
			return u;
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
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};
struct edge {
	int u;
	int v;
	int cost;

	bool operator<(const edge& e) const {
		return cost < e.cost;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int V, E; // 정점, 간선
	cin >> V >> E;

	vector<edge> edges; // graph[a][b] = a에서 b로 가는 비용
	for (int i = 0; i < E; i++)
	{
		int a, b, c; // a에서 b로 가는 비용 c
		cin >> a >> b >> c;

		edges.push_back({ a, b, c });
	}
	
	sort(edges.begin(), edges.end());

	DSU dsu(V + 1);
	int totalCost = 0;
	for (auto& edge : edges)
	{
		if (!dsu.same(edge.u, edge.v))
		{
			dsu.merge(edge.u, edge.v);
			totalCost += edge.cost;
		}
	}

	cout << totalCost;

	return 0;
}