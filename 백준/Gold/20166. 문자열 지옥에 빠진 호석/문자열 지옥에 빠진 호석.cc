#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M, K;
vector<vector<char>> board;

int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 }; // left, left-up, up, up-right, right, right-down, down, down-left
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // left, left-up, up, up-right, right, right-down, down, down-left

unordered_map<string, int> um; // 문자열, 경우의 수

void DFS(int y, int x, int depth, string& str)
{
    um[str]++;

    if (depth == 5)
    {
        return;
    }
    for (int dir = 0; dir < 8; dir++)
    {
        int ny = (y + dy[dir] + N) % N;
        int nx = (x + dx[dir] + M) % M;

		str.push_back(board[ny][nx]);
        DFS(ny, nx, depth + 1, str);
		str.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    board.assign(N, vector<char>(M));
    um.reserve(26 * 26 * 5);
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = str[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            string s;
            s.reserve(5);
			s.push_back(board[i][j]);
            DFS(i, j, 1, s);
        }
    }

    for (int i = 0; i < K; i++)
    {
        string s;
        cin >> s;

        cout << um[s] << "\n";
    }

    return 0;
}
