#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
	int k, n;

	cin >> k >> n;
	list<string> li;
	unordered_map<string, list<string>::iterator> um;

	for (int i = 0; i < n; i++)
	{
		string id;
		cin >> id;

		auto it = um.find(id);
		if (it != um.end())
		{
			// 기존꺼 제거
			li.erase(it->second);
			um.erase(id);
		}

		li.push_back(id);
		um[id] = prev(li.end());
	}

	int cnt = 0;
	for (auto it = li.begin(); it != li.end() && cnt < k; cnt++, ++it)
	{
		cout << *it << "\n";
	}

	return 0;
}