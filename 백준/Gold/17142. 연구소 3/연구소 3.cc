#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> virus;
vector<int> selected;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, m;
int emptyCnt = 0;
int answer = INT_MAX;

int SpreadVirus()
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));

    for (int idx : selected)
    {
        auto [y, x] = virus[idx];
        q.push({ y, x });
        dist[y][x] = 0;
    }

    int infected = 0;
    int maxTime = 0;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (board[ny][nx] == 1)
                continue;
            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny, nx });

            // 빈칸일 때만 감염 수 / 시간 갱신
            if (board[ny][nx] == 0)
            {
                infected++;
                maxTime = max(maxTime, dist[ny][nx]);
            }
        }
    }

    if (infected != emptyCnt)
        return INT_MAX;

    return maxTime;
}

void ChooseVirus(int idx, int cnt)
{
    if (cnt == m)
    {
        answer = min(answer, SpreadVirus());
        return;
    }

    if (idx == virus.size())
        return;

    selected.push_back(idx);
    ChooseVirus(idx + 1, cnt + 1);
    selected.pop_back();

    ChooseVirus(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                emptyCnt++;
            else if (board[i][j] == 2)
                virus.push_back({ i, j });
        }
    }

    if (emptyCnt == 0)
    {
        cout << 0;
        return 0;
    }

    ChooseVirus(0, 0);

    if (answer == INT_MAX) cout << -1;
    else cout << answer;

    return 0;
}