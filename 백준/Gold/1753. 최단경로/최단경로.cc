#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int V, E;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start)
{
	dist.assign(V + 1, INT_MAX);

	// 거리, 노드
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();

		if (d != dist[u]) continue;

		for (auto [v, w] : graph[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
}

int main() 
{
	cin >> V >> E;
	graph.assign(V + 1, {});
	int start;
	cin >> start;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}
	
	dijkstra(start);
	
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
    return 0;
}