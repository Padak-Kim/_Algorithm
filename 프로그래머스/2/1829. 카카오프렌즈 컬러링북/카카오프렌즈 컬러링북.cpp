#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> visited;
int number_of_area = 0;
int max_size_of_one_area = 0;
int M, N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(const vector<vector<int>>& picture, int start_y, int start_x, int& cnt)
{
    int color = picture[start_y][start_x];
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = 1;
    cnt = 1;

    while (!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue;
            if (picture[ny][nx] != color) continue;

            visited[ny][nx] = 1;
            cnt++;
            q.push({ny, nx});
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    // ★ 전역값 초기화 필수
    number_of_area = 0;
    max_size_of_one_area = 0;

    M = m; N = n;
    visited = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j]) continue;
            if (picture[i][j] == 0) continue;

            int cnt = 0;
            BFS(picture, i, j, cnt);
            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, cnt);
        }
    }

    return {number_of_area, max_size_of_one_area};
}
