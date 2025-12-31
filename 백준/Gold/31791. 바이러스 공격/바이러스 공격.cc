#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

struct Node
{
	int t;
	int y;
	int x;
	bool operator <(const Node& other) const
	{
		return t > other.t;
	}
};
int N, M;

vector<vector<char>> board;
priority_queue<Node, vector<Node>> pq;

int dirX[4] = { 0, 0, -1, 1 };// up, down, left, right
int dirY[4] = { -1, 1, 0, 0 };// up, down, left, right

int main()
{
	cin >> N >> M;
	board.assign(N, vector<char>(M, ' '));
	vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
	int G, B, X, C;
	// 바이러스가 전파되는 시간, 건물에서 전파가 지연되는 시간, 처음 바이러스가 살포된 지점의 개수, 건물의 개수
	cin >> G >> B >> X >> C;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		// * 바이러스가 살포된 곳, # 건물이 있는 곳, . 빈 곳을 의미
		for (int j = 0; j < M; j++)
		{
			board[i][j] = s[j];
			if (s[j] == '*')
			{
				pq.push(Node{ 0, i, j });
				dist[i][j] = 0;
			}
		}
	}

	while (!pq.empty())
	{
		auto[t, y, x] = pq.top(); pq.pop();

		if (t != dist[y][x]) continue;
		for (int i = 0; i < 4; i++)
		{
			int new_ypos = y + dirY[i];
			int new_xpos = x + dirX[i];

			if (new_ypos < 0 || new_ypos >= N || new_xpos < 0 || new_xpos >= M)
				continue;
			if (board[new_ypos][new_xpos] == '*')
				continue;
			else if (board[new_ypos][new_xpos] == '#')
			{
				if (dist[new_ypos][new_xpos] > t + B && G >= t + B + 1)
				{
					dist[new_ypos][new_xpos] = t + B + 1;
					pq.push(Node{ t + B + 1, new_ypos, new_xpos });
				}
			}
			else
			{
				if (dist[new_ypos][new_xpos] > t + 1 && G >= t + 1)
				{
					dist[new_ypos][new_xpos] = t + 1;
					pq.push(Node{ t + 1, new_ypos, new_xpos });
				}
			}
		}
	}

	bool check = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dist[i][j] == INT_MAX)
			{
				check = true;
				cout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}
	if (!check)
		cout << "-1";
	return 0;
}