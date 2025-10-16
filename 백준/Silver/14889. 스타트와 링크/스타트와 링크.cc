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
#include <climits>
#include <sstream>
#include <math.h>
using namespace std;

int answer = INT_MAX;
void DFS(int n, vector<vector<int>>& S, vector<int>& join, vector<int> sTeam)
{
	int T = n / 2;

	if (sTeam.size() == n / 2)
	{
		// sTeam 점수 계산
		int sTeamScore = 0;
		for (int x : sTeam)
		{
			for (int y : sTeam)
			{
				sTeamScore += S[x][y];
			}
		}

		vector<int> lTeam;
		// lTeam 생성
		for (int i = 2; i <= n; i++)
		{
			if (join[i] != 1)
				lTeam.push_back(i);
		}

		// lTeam 점수 계산
		int lTeamScore = 0;
		for (int x : lTeam)
		{
			for (int y : lTeam)
			{
				lTeamScore += S[x][y];
			}
		}

		answer = min(answer, abs(sTeamScore - lTeamScore));
	}

	for (int i = 2; i <= n; i++)
	{
		if (sTeam.size() > 1 && sTeam[sTeam.size() - 1] > i) continue;

		if (sTeam.size() < n / 2 && join[i] != 1)
		{
			join[i] = 1;
			sTeam.push_back(i);
			DFS(n, S, join, sTeam);
			join[i] = 0;
			sTeam.pop_back();
		}
	}
}
int main() 
{
	int n;
	cin >> n;
	vector<vector<int>> S(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> S[i][j];
		}
	}
	vector<int> sTeam;
	sTeam.push_back(1); // 1은 항상 s팀
	vector<int> join(n + 1, 0);
	join[1] = 1;
	DFS(n, S, join, sTeam);

	cout << answer;
}