#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int u;
    int v;
    int cost;
    
    bool operator<(const Edge& e) const
    {
        return cost < e.cost;
    }
};
struct DSU{
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 1)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u == parent[u])
            return u;
        
        return parent[u] = find(parent[u]);
    }
    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if (a == b)
            return;
        
        if (rank[a] < rank[b])
            swap(a, b);
        
        parent[b] = a;
        
        if (rank[a] == rank[b])
            rank[a]++;
        
        return;
    }
    
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<Edge> edges(n);
    for(vector<int> cost : costs)
        edges.push_back({cost[0], cost[1], cost[2]});
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    for (auto& edge : edges)
    {
        if (!dsu.same(edge.u, edge.v))
        {
            dsu.merge(edge.u, edge.v);
            answer += edge.cost;
        }
    }
    return answer;
}