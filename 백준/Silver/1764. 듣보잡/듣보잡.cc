#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<string> res;

	set<string> s1;
	int n, m, count = 0;
	string name;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		s1.insert(name);
		
	}
	
	for (int i = 0; i < m; i++) {
		cin >> name;
		auto it = s1.find(name);
		if (it != s1.end()) {
			res.insert(name);
			count++;
		}
			
	}
	cout << count << "\n";
	for (auto it = res.begin(); it != res.end(); ++it) {
		cout << *it << "\n";
	}
	return 0;
}

