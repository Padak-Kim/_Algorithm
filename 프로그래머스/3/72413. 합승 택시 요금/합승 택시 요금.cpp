#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph;

void Dijkstra(int start, vector<int>& dist)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        
        for(auto [v, w] : graph[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    graph.assign(n + 1, {});
    for(int i = 0; i < fares.size(); i++)
    {
        int u, v, w;
        u = fares[i][0];
        v = fares[i][1];
        w = fares[i][2];
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    vector<int> distS(n + 1, INT_MAX);
    vector<int> distA(n + 1, INT_MAX);
    vector<int> distB(n + 1, INT_MAX);
    
    Dijkstra(s, distS);
    Dijkstra(a, distA);
    Dijkstra(b, distB);
    
    int minCost = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        if (distS[i] != INT_MAX && distA[i] != INT_MAX && distB[i] != INT_MAX)
        {
            int cost = distS[i] + distA[i] + distB[i];
            
            minCost = min(minCost, cost);
        }
    }
    answer= minCost;
    return answer;
}