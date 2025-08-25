#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> win(n+1, vector<bool>(n + 1, false));
    for (auto& result : results)
    {
        int u = result[0]; int v = result[1];
        win[u][v] = true;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (win[i][k])
            {
                for(int j = 1; j <= n; j++)
                {
                    if(win[k][j])  
                        win[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int wins = 0; int losses = 0;
        for (int j = 1; j <= n; j++)
        {
            if (win[i][j]) wins++;
            if (win[j][i]) losses++;
        }
        if (wins + losses == n - 1) answer++;
    }
    
    
    return answer;
}