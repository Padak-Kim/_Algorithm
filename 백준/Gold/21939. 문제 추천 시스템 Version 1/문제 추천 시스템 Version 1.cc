#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int P, L;
	unordered_map<int, int> um;
	set<pair<int, int>> st;

	for (int i = 0; i < T; i++)
	{
		cin >> P >> L;
		
		um.insert({ P, L });
		st.insert({ L, P });
	}
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		string s; cin >> s;
		if (s == "add")
		{
			int P, L;
			cin >> P >> L;
			um.insert({ P, L });
			st.insert({ L, P });
		}
		else if(s == "recommend")
		{
			int x; cin >> x;
			if (x == 1)
			{
				auto it = prev(st.end());
				cout << it->second << "\n";
			}
			else
			{
				auto it = st.begin();
				cout << it->second << "\n";
			}
		}
		else if(s == "solved")
		{
			int x; cin >> x;
			int l = um[x];
			st.erase({ l, x });
			um.erase(x);
		}
	}
	return 0;
}