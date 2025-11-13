#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int N, M, X;

vector<vector<pair<int, int>>> graph;

void Dijkstra(int start, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();

		if (dist[cur] < cost) continue;
		for (auto [next, weight] : graph[cur])
		{
			if (dist[next] > cost + weight)
			{
				dist[next] = cost + weight;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() 
{
	cin >> N >> M >> X;
	graph.assign(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		vector<int> distFromStart(N + 1, INT_MAX);
		vector<int> distFromX(N + 1, INT_MAX);

		Dijkstra(i, distFromStart);
		Dijkstra(X, distFromX);
		answer = max(answer, distFromStart[X] + distFromX[i]);
	}

	cout << answer << "\n";
    return 0;
}