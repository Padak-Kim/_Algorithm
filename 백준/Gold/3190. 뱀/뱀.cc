#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
int n, k;
using namespace std;
vector<vector<int>> board;
deque<pair<int, int>> dq;
unordered_map<int, char> um;

int dirX[4] = { 1, 0, -1, 0 }; // right, down, left, up
int dirY[4] = { 0, 1, 0, -1 }; // right, down, left, up
int main()
{
	cin >> n;
	board.assign(n + 1, vector<int>(n + 1, 0));
	cin >> k; // 사과의 개수
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		
		board[y][x] = 1; // 1인 곳은 사과
	}
	int L;
	cin >> L; // 뱀의 방향 변환 횟수

	for (int i = 0; i < L; i++)
	{
		int x; // 게임 시작 시간으로부터 x초
		char c; // c가 'L'왼쪽 또는 'D'오른쪽으로 90도 회전
		cin >> x >> c;
		um[x] = c;
	}
	int time = 0;
	int dir = 0; // 오른쪽 방향 진행중
	dq.push_back({ 1, 1 }); // 1,1 시작
	board[1][1] = 2; // 뱀 몸
	bool gameover = false;
	while (!gameover)
	{
		time++;
		int head_ypos = dq.front().first;
		int head_xpos = dq.front().second;

		int new_ypos = head_ypos + dirY[dir];
		int new_xpos = head_xpos + dirX[dir];

		// 벽 부딪힘
		if (new_ypos <= 0 || new_ypos > n || new_xpos <= 0 || new_xpos > n)
		{
			cout << time;
			gameover = true;
			break;
		}

		if (board[new_ypos][new_xpos] == 2) // 뱀 몸과 부딪힘
		{
			cout << time;
			gameover = true;
			break;
		}
		if (board[new_ypos][new_xpos] != 1) // 사과 없음
		{
			int y = dq.back().first;
			int x = dq.back().second;
			dq.pop_back(); // 꼬리 제거
			
			board[y][x] = 0;
		}
		else
			board[new_ypos][new_xpos] = 0; // 사과 제거

		dq.push_front({ new_ypos, new_xpos }); // 머리 이동
		board[new_ypos][new_xpos] = 2;

		if (um.count(time))
		{
			if (um[time] == 'L')
			{
				// 왼쪽으로 90도 회전
				dir = (dir + 3) % 4;
			}
			else if (um[time] == 'D')
			{
				// 오른쪽으로 90도 회전
				dir = (dir + 1) % 4;
			}

		}
	}
	return 0;
}