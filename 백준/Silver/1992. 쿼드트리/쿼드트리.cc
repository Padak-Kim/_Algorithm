#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void QuadTree(vector<string>& board, int start_x, int start_y, int size)
{
	bool check = true;
	int first_value = board[start_y][start_x];
	for (int i = start_y; i < size + start_y; i++)
	{
		for (int j = start_x; j < size + start_x; j++)
		{
			if (first_value != board[i][j])
			{
				check = false;
				break;
			}
		}
		if (!check) break;
	}

	if (check)
	{
		cout << first_value - '0';
		return;
	}
	else
	{
		cout << "(";
		int half = size / 2;
		QuadTree(board, start_x, start_y, half);
		QuadTree(board, start_x + half, start_y, half);
		QuadTree(board, start_x, start_y + half, half);
		QuadTree(board, start_x + half, start_y + half, half);
		cout << ")";
	}
}
int main()
{
	int N;
	cin >> N;

	vector<string> board(N);
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	

	QuadTree(board, 0, 0, board.size());
}