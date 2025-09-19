#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> visited;

int Dfs(vector<vector<int>>& graph, int start, int& cnt)
{
    visited[start] = true;
    
    for (int &v : graph[start])
    {
        if (visited[v] == true) continue;
        if (v == -1)    continue;
        visited[v] = true;
        cnt++;
        //cout << "v : " << v << " cnt : " << cnt << endl;
        Dfs(graph, v, cnt);
    }
    
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    vector<vector<int>> graph;
    graph.assign(n + 1, {});
    int minNum = 99999;
    
    for (auto& wire : wires)
    {
        int a = wire[0]; int b = wire[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (auto& wire : wires)
    {
        visited.assign(n + 1, false);
        int start = wire[0];
        int block = wire[1];
        
        visited[block] = true;
        int cnt = 1;
        int cnt1 = Dfs(graph, start, cnt);
        int cnt2 = n - cnt1;
        
        //cout << "----------------------" << endl;
        //cout << start << ", " << block << endl;
        //cout << cnt1 << ", " << cnt2 << endl;
        //cout << "----------------------" << endl;
        minNum = min(minNum, abs(cnt1 - cnt2));
    }
    
    
    return minNum;
}