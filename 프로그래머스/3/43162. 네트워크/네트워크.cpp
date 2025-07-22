#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<bool> visited;
void dfs(int n, vector<vector<int>> computers, int index)
{
    // 방문
    visited[index] = true;
    answer++;
    for(int i = 0; i < computers[index].size(); i++)
    {
        if (index == i) continue;
        
        if (computers[index][i] == 1 && !visited[i])
        {
            dfs(n, computers, i);
            answer--;
        }
        
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited = vector<bool>(n, false);
    
    for(int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        
        dfs(n, computers, i);
    }
    
    return answer;
}