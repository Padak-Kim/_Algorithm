#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int color, x;

	int answer = 0;
	unordered_map<int, vector<int>> um;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> color;
		um[color].push_back(x);
	}

	for (auto& [c, v] : um)
	{
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			if (i == 0)
			{
				answer += v[i + 1] - v[i];
			}
			else if(i == v.size() - 1)
			{
				answer += v[i] - v[i - 1];
			}
			else
			{
				answer += min(v[i] - v[i - 1], v[i + 1] - v[i]);
			}
		}
	}
	
	cout << answer;
	return 0;
}