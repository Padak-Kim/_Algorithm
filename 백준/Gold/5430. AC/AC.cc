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

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string cmd; cin >> cmd;
		int n; cin >> n;

		string a; cin >> a;
		vector<int> v;
		v.reserve(n);
		
		string num = "";
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] >= '0' && a[i] <= '9')
				num += a[i];
			else
			{
				if (num != "")
				{
					v.push_back(stoi(num));
					num = "";
				}
			}
		}
		
		vector<int> res(v.size());

		bool error = false;
		bool R = false;
		for (char c : cmd)
		{
			if (c == 'R')
				R = !R;
			else
			{
				if (v.empty())
				{
					cout << "error\n";
					error = true;
					break;
				}
				else
				{
					if (R)
						v.erase(v.end() - 1);
					else
						v.erase(v.begin());
				}
			}
		}
		if (!error)
		{
			if (R)
				reverse(v.begin(), v.end());

			cout << "[";
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i != v.size() - 1)
					cout << ",";
			}

			cout << "]\n";
		}
	}
}
