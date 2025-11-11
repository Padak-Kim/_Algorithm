#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<vector<int>>> dist;

int dx[4] = { -1, 1, 0, 0 }; // left, right, up, down
int dy[4] = { 0, 0, -1, 1 }; // left, right, up, down
void BFS(int x, int y)
{
	queue<tuple<int, int, int>> q;

	q.push({ x, y, 0 });

	while (!q.empty())
	{
		auto [cx, cy, b] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			if (board[ny][nx] == 1 && b == 0 && dist[ny][nx][1] == 0)
			{
				dist[ny][nx][1] = dist[cy][cx][0] + 1;
				q.push({ nx,ny,1 });
			}
			else if (board[ny][nx] == 0 && dist[ny][nx][b] == 0)
			{
				dist[ny][nx][b] = dist[cy][cx][b] + 1;
				q.push({ nx,ny,b });
			}

		}
	}
}
int main() 
{
	cin >> N >> M;

	board.resize(N, vector<int>(M, 0));
	dist.resize(N, vector<vector<int>>(M, vector<int>(2, 0)));
	dist[0][0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for(int j = 0; j < str.length(); j++)
		{
			int num = str[j] - '0';
			board[i][j] = num;
		}
	}

	BFS(0, 0);

    int a = dist[N-1][M-1][0];
    int b = dist[N-1][M-1][1];
    if (a==0 && b==0) cout << -1 << "\n";
    else if (a==0)    cout << b << "\n";
    else if (b==0)    cout << a << "\n";
    else              cout << min(a,b) << "\n";
    return 0;
}