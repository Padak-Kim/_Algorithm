#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m;

int dx[4] = {-1, 1, 0, 0}; // left, right, up, down
int dy[4] = {0, 0, -1, 1};
int cnt = 0;
void BFS(int y, int x)
{
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;
    cnt++;

    while (!q.empty())
    {
        auto [cy, cx] = q.front();
		q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (grid[ny][nx] == 0 || visited[ny][nx])
                continue;

            q.push({ ny, nx });
            visited[ny][nx] = true;
        }
    }
}
int main() 
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int M, N, K;
        cin >> M >> N >> K;
		n = N;
		m = M;
        cnt = 0;
        grid.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<bool>(M, false));
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
				if (grid[i][j] == 1 && !visited[i][j])
                    BFS(i, j);

		cout << cnt << "\n";
    }
    return 0;
}