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

void CutPaper(vector<vector<int>>& board, int start_x, int start_y, int size, int& white, int& blue)
{
	int first_color = board[start_y][start_x];
	bool same = true;

	for (int i = start_y; i < start_y + size; i++)
	{
		for (int j = start_x; j < start_x + size; j++)
		{
			if (board[i][j] != first_color)
			{
				same = false;
				break;
			}
		}
		if (!same) break;
	}

	if (same)
	{
		if (first_color == 1) blue++;
		else white++;
	}
	else
	{
		int half = size / 2;
		CutPaper(board, start_x, start_y, half, white, blue);
		CutPaper(board, start_x + half, start_y, half, white, blue);
		CutPaper(board, start_x, start_y + half, half, white, blue);
		CutPaper(board, start_x + half, start_y + half, half, white, blue);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	int blue = 0;
	int white = 0;

	CutPaper(board, 0, 0, N, white, blue);

	cout << white << "\n" << blue;
}