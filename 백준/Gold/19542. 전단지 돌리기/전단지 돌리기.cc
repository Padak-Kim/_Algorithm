#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
    
vector<vector<int>> graph;

int cnt;
int N, S, D;
int DFS(int start, int parent)
{
    int best = 0;
    bool isLeaf = true;

    for (int v : graph[start])
    {
        if (v == parent) continue;
        
        isLeaf = false;
        int h = DFS(v, start) + 1;
        if (h > D) 
            cnt += 2;
        best = max(best, h);
    }

return isLeaf ? 0 : best;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S >> D;
    graph.resize(N + 1);
    cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(S, 0);

    cout << cnt;

    return 0;
}