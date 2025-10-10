#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct DSU
{
	vector<int> parent, size, rank;

	DSU(int n) : parent(n + 1), size(n + 1, 1), rank(n + 1, 0)
	{
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int a)
	{
		if (parent[a] == a)
			return a;
		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return;

		if (rank[a] > rank[b])
			swap(a, b);

		parent[a] = b;

		if (rank[a] == rank[b])
			rank[b]++;

		size[b] += size[a];
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	for (int i = 0; i < m; i++)
	{
		int B, a, b;
		cin >> B >> a >> b;

		if (B == 0)
		{
			// union
			dsu.merge(a, b);
		}
		else
		{
			// find
			if (dsu.same(a, b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}