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
	string s, searchWord;
	getline(cin, s);
	getline(cin, searchWord);
	int res = 0;

	int n = searchWord.size();

	for (int i = 0; i + n <= s.size(); i++)
	{
		if (s.substr(i, n) == searchWord)
		{
			res++;
			i += n - 1;
		}
	}

	cout << res;
	return 0;
}