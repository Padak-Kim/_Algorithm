#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> Tempboard;
vector<pair<int, int>> emptySpace;
vector<pair<int, int>> virus;

int dx[4] = { 0, 0, -1, 1 }; // up, down, left, right
int dy[4] = { -1, 1, 0, 0 }; // up, down, left, right
int n, m;
void SpreadVirus()
{
    queue<pair<int, int>> q;
    Tempboard.clear();
    Tempboard.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Tempboard[i][j] = board[i][j];
     
    for (auto& v : virus)
        q.push(v);

    while (!q.empty())
    {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (Tempboard[ny][nx] != 0)
                continue;

            Tempboard[ny][nx] = 2;
            q.push({ ny, nx });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    board.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                emptySpace.push_back({ i, j });
            else if (board[i][j] == 2)
                virus.push_back({ i, j });
        }
    }

    int maxSafeSpace = 0;
    for (int i = 0; i < emptySpace.size(); i++)
    {
        for (int j = i + 1; j < emptySpace.size(); j++)
        {
            for (int k = j + 1; k < emptySpace.size(); k++)
            {
                auto [x1, y1] = emptySpace[i];
                auto [x2, y2] = emptySpace[j];
                auto [x3, y3] = emptySpace[k];

                board[x1][y1] = 1;
                board[x2][y2] = 1;
                board[x3][y3] = 1;

                SpreadVirus();

                int cnt = 0;
                for (int y = 0; y < n; y++)
                {
                    for (int x = 0; x < m; x++)
                    {
                        if (Tempboard[y][x] == 0)
                            cnt++;
                    }
                }

                maxSafeSpace = max(cnt, maxSafeSpace);

                board[x1][y1] = 0;
                board[x2][y2] = 0;
                board[x3][y3] = 0;
            }
        }
    }

    cout << maxSafeSpace;
    return 0;
}