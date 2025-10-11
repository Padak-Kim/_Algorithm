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

void PaperNum(vector<vector<int>>& board, int start_x, int start_y, int size, int& minusCnt, int& zeroCnt, int& oneCnt)
{
	int firstNum = board[start_x][start_y];
	bool isSame = true;
	for (int i = start_x; i < start_x + size; i++)
	{
		for (int j = start_y; j < start_y + size; j++)
		{
			if (board[i][j] != firstNum)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	if (isSame)
	{
		if (firstNum == 1) oneCnt++;
		else if (firstNum == 0) zeroCnt++;
		else if (firstNum == -1) minusCnt++;
	}
	else
	{
		int newSize = size / 3;
		PaperNum(board, start_x, start_y, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x, start_y + newSize, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x, start_y + 2 * newSize, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + newSize, start_y, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + newSize, start_y + newSize, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + newSize, start_y + 2 * newSize, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + 2 * newSize, start_y, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + 2 * newSize, start_y + newSize, newSize, minusCnt, zeroCnt, oneCnt);
		PaperNum(board, start_x + 2 * newSize, start_y + 2 * newSize, newSize, minusCnt, zeroCnt, oneCnt);
	}
}
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int minusCnt = 0;
	int zeroCnt = 0;
	int oneCnt = 0;
	PaperNum(board, 0, 0, board.size(), minusCnt, zeroCnt, oneCnt);

	cout << minusCnt << "\n" << zeroCnt << "\n" << oneCnt;
}