#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
	pair<int, int> board[26];

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{

			int num;
			cin >> num;
			board[num] = { i, j };
		}
	}
	int row[5] = { 0, };
	int col[5] = { 0, };
	int diag[2] = { 0, };
	
	int bingo = 0;
	for (int i = 1; i <= 25; i++)
	{
		int num;
		cin >> num;

		auto [r, c] = board[num];

		if (++row[r] == 5) ++bingo;
		if (++col[c] == 5) ++bingo;

		// 대각선 체크
		if (r == c) {
			if (++diag[0] == 5) ++bingo;
		}
		if (r + c == 4) {
			if (++diag[1] == 5) ++bingo;
		}

		if (bingo >= 3) {
			cout << i << "\n";
			return 0;
		}
	}

	return 0;
}