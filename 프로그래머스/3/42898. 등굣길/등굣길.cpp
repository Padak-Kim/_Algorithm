#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> board(n, vector<int>(m, 1));

    for (const auto& pos : puddles) 
    {
        int x = pos[0];
        int y = pos[1];
        board[y - 1][x - 1] = 0;
    }

    dp[0][0] = 1;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (board[y][x] == 0) {
                dp[y][x] = 0;
                continue;
            }
            if (y > 0) dp[y][x] = (dp[y][x] + dp[y - 1][x]) % MOD;
            if (x > 0) dp[y][x] = (dp[y][x] + dp[y][x - 1]) % MOD;
        }
    }
    return dp[n - 1][m - 1];
}
