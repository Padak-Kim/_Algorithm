#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
void DFS(int start, int& cnt)
{
    visited[start] = true;
    for (int x : graph[start])
    {
        if (!visited[x])
        {
            cnt++;
            DFS(x, cnt);
        }
	}
}
int main() 
{
    int M, N;
	cin >> N >> M;
    graph.resize(N + 1);
	visited.assign(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int x, y;
		cin >> x >> y;
		graph[y].push_back(x);
    }

	vector<int> result(N + 1, 0);
    for(int i = 1; i <= N; i++)
    {
        visited.assign(N + 1, false);
        int cnt = 1;
        DFS(i, cnt);
        result[i] = cnt;
	}

    int max_value = *max_element(result.begin(), result.end());

    for(int i = 1; i <= N; i++)
    {
        if(result[i] == max_value)
            cout << i << " ";
	}
	
    return 0;
}