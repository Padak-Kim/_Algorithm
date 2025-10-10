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
	vector<int> parent, rank, size;

	DSU(int n) : parent(n), rank(n, 0), size(n, 1)
	{
		for (int i = 0; i < n; i++)
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

		return;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};
int main()
{
	int N, M;
	cin >> N >> M;

	DSU dsu(N);
	vector<int> plans(M, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int city;
			cin >> city;

			if (city == 1)
				dsu.merge(i, j);
		}
	}

	bool ok = true;
	for (int i = 0; i < M; i++)
	{
		int city;
		cin >> city;

		plans[i] = city - 1;
	}

	for (int i = 0; i < M - 1; i++)
	{
		if (!dsu.same(plans[i], plans[i + 1]))
			ok = false;
	}

	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}