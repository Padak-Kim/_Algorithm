#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> adj(n + 1);
    for (auto &e : edge)
    {
        int u = e[0]; int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    q.push(1); // 1 시작
    while(!q.empty())
    {
        int n = q.front(); q.pop();
        
        for(auto& v : adj[n])
        {
            if (dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[n] + 1;
            }
        }
    }
    
    int maxDist = *max_element(dist.begin() + 1, dist.end());
    int answer = count(dist.begin() + 1, dist.end(), maxDist);
    
    return answer;
}