#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist1, dist2, dist3;
int V, E;

void Dijkstra(int start, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		auto [cost, now] = pq.top();
		pq.pop();

		if (dist[now] != cost) continue;

		for (auto [next, nextCost] : graph[now])
		{
			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() 
{
	cin >> V >> E;
	graph.assign(V + 1, {});
	dist1.assign(V + 1, INT_MAX);
	dist2.assign(V + 1, INT_MAX);
	dist3.assign(V + 1, INT_MAX);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}


	int v1, v2;
	cin >> v1 >> v2;
	Dijkstra(1, dist1);
	Dijkstra(v1, dist2);
	Dijkstra(v2, dist3);

	int path = INT_MAX;
	if (dist1[v1] != INT_MAX && dist2[v2] != INT_MAX && dist3[V] != INT_MAX)
		path = dist1[v1] + dist2[v2] + dist3[V];

	int path2 = INT_MAX;
	if (dist1[v2] != INT_MAX && dist3[v1] != INT_MAX && dist2[V] != INT_MAX)
		path2 = dist1[v2] + dist3[v1] + dist2[V];

	int ans = min(path, path2);
	if (ans == INT_MAX) cout << -1 << '\n';
	else cout << ans << '\n';
    return 0;
}