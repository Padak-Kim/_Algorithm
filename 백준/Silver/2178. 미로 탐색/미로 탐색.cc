#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> dist;
vector<vector<bool>> visited;
int dy[4] = { 0, 0, -1, 1 }; // Left, Right, Up, Down
int dx[4] = { -1, 1, 0, 0 }; // Left, Right, Up, Down
void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({ y, x });
	dist[y][x] = 1;
    while (!q.empty())
    {
        auto [cy, cx] = q.front(); q.pop();
		visited[cy][cx] = true;

        if (cy == board.size() - 1 && cx == board[0].size() - 1)
        {
            cout << dist[cy][cx] << "\n";
            return;
		}

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size())
				continue;
            if (visited[ny][nx] || board[ny][nx] == 0)
                continue;

			dist[ny][nx] = dist[cy][cx] + 1;
			visited[ny][nx] = true;
			q.push({ ny, nx });
        }
    }
}
int main() 
{
    int N, M;
    cin >> N >> M;
	board.resize(N, vector<int>(M, 0));
	dist.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        string num;
        cin >> num;
        
        for(int j = 0; j < num.size(); j++)
        {
            board[i][j] = num[j] - '0';
		}
    }
    BFS(0, 0);
    return 0;
}