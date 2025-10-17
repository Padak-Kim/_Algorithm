#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxSheep = 0;
void DFS(vector<int>& info, vector<vector<int>>& graph, vector<int> nextNodes, int sheep, int wolf)
{
    maxSheep = max(maxSheep, sheep);
    for(int i = 0; i < nextNodes.size(); i++)
    {
        int cur = nextNodes[i];
        
        // 현재 위치 후보군에서 제거
        vector<int> next = nextNodes;
        next.erase(next.begin() + i);
        
        // 현재 위치의 자식들 후보군에 추가
        for(int n : graph[cur])
            next.push_back(n);
        
        if (info[cur] == 0) // 양
        {
            DFS(info, graph, next, sheep + 1, wolf);
        }
        else // 늑대
        {
            if (sheep > wolf + 1)
            {
                DFS(info, graph, next, sheep, wolf + 1);
            }
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<vector<int>> graph(info.size());
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    DFS(info, graph, graph[0], 1, 0);
    
    answer = maxSheep;
    return answer;
}