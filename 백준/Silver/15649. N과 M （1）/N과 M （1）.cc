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
#include <climits>
#include <sstream>
using namespace std;

void DFS(int n, int m, vector<int>& visited, vector<int>& arr ,int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;
		arr[cnt] = i;
		DFS(n, m, visited, arr, cnt + 1);
		visited[i] = 0;
	}

	return;
}
int main() {
    int n, m;
	cin >> n >> m;

	vector<int> visited(n + 1, 0);
	vector<int> arr(9);

	DFS(n, m, visited, arr, 0);
}