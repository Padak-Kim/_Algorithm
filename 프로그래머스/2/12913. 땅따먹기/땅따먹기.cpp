#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int m = 4;
    int n = land.size();
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int bestPrev = 0;
            for(int p = 0; p < 4; p++)
            {
                if (p == j) 
                    continue;
                bestPrev = max(bestPrev, dp[i - 1][p]);
            }
            
            dp[i][j] = bestPrev + land[i][j];
        }
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
}