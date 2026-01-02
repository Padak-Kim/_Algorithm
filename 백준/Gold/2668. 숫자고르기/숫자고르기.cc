#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<int> graph;
vector<int> res;
vector<int> visited;
vector<int> cycle;
void DFS(int here)
{
	visited[here] = 1;

	int newPos = graph[here];

	if (visited[newPos] == 0) // 미방문
	{
		DFS(newPos);
	}
	else // 방문
	{
		if (cycle[newPos] == 0)
		{
			cycle[newPos] = 1;
			DFS(newPos);
			res.push_back(newPos);
		}
	}
}
int main()
{
	cin >> N;
	graph.assign(N + 1, -1);
	cycle.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		graph[i] = num;
	}

	for (int i = 1; i <= N; i++)
	{
		visited.assign(N + 1, 0);
		DFS(i);
	}
	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (int r : res)
		cout << r << "\n";
	return 0;
}