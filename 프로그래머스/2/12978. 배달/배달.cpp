#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int answer = 0;
    
vector<vector<pair<int, int>>> graph;
vector<int> dist;
void Dijkstra(int start, int k)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    // dist, u
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        
        if (dist[u] != d)   continue;
        
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
int solution(int N, vector<vector<int> > road, int K) {
    graph.assign(N + 1, {});
    dist.assign(N + 1, INT_MAX);
    for(int i = 0; i < road.size(); i++)
    {
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    answer = 0;
    
    Dijkstra(1, K);
    
    for(int x : dist)
    {
        if (x <= K)
            answer++;
    }
    return answer;
}